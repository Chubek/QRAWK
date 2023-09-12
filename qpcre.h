#ifndef Q_PRE_H_
#define Q_PRE_H_

#include <pcre.h>
#include <stdint.h>
#include <stdlib.h>

#define SUBSET_VEC_MAX 		0x1000
#define CCRE_FAIL		0xFF
#define CCRE_SUCCESS		0x80
#define MARK_STAT_FAIL(STAT)		((STAT << 32) | CCRE_FAIL)
#define MARK_STATS_SUCCESS(STAT)	((STAT << 32) | CCRE_SUCCESS)
#define IS_STAT_FAIL(STAT)		((STAT & 0xFF) == CCRE_FAIL)
#define IS_STAT_SUCCESS(STAT)		((STAT & 0xFF) == CCRE_SUCCESS)
#define GET_STR_COUNT(QUERY)						\
	((pquery->match_num = 0) ? (SUBSET_VEC_MAX / 3) : pquery->matchnum)

typedef pcre		*qPREgex;
typedef uint8_t		*qPREPattern, *qPREStrBuffer;
typedef int32_t		qPREOpts;
typedef uint64_t 	qPRECCStat;
typedef uint64_t	qPREMatchStat;

typedef struct {
	uint8_t		*subject;
	int32_t		ovector[SUBSET_VEC_MAX], matched_num, next_match;
	uint64_t	subject_len;
} qPREQuery;

typedef struct {
	qPREgex		compiled_re;
	qPREPattern	raw_pattern;
	qPREOpts		re_opts;
	qPREAction	re_action;
} qPRE;

static inline qPRE*
new_pregex(qPREPattern raw_pattern, qPREAction action)
{
	qPRE	*re		= calloc(1, sizeof(qPRE));
	re->raw_pattern 	= raw_pattern;
	re->re_action  		= action;
	return re;
}

static inline qPREQuery*
new_pquery(uint8_t *subject)
{
	qPREQuery	*pquery	= calloc(1, sizeof(qPREQuery));
	pquery->subject		= subject;
	return pquery;
}

static inline void
free_pregex(qPRE *re)
{
	free(re);
}

static inline void
free_pquery(qPREQUery *pquery)
{
	free(pquery);
}

static inline qPRECCStat
compile_pregex(qPRE *re)
{
	int error_code, error_offset;
	char *error;
	re->compiled_re 	= pre_compile2(
						re->raw_pattern,
						PRE_CONFIG_UTF8,
						&error_code,
						(const char**)&error,
						&error_offset,
						NULL,
					);
	if (!re->compiled_re)
		return MARK_STAT_FAIL(error_core);
	else
		return MARK_STAT_SUCCESS(error_code);
}

static inline void
match_pregex(qPRE *re, qPREQuery *pquery)
{
	pquery->match_num = pcre_exec(											(const pcre*)re->compiled_re,
					NULL,
					pquery->subject,
					pquery->subject_len,
					0,
					0,
					pquery->ovector,
					SUBJECT_VEC_MAX,
				);
}

static inline void
prequery_nextsubstr_iter(qPREQuery *pquery, qPREStrBuffer *buffer)
{
	return pcre_get_substring(
				pquery->subject, 
				pquery->ovector,
				pquery->match_num,
	 			pquery->next_match++,
				(const char *)buffer,
			);
}

static inline void
prequery_getsubstr_named(qPRE *re, 
		qPREQuery *pquery, 
		qPREStrBuffer name, 
		qPREStrBuffer *buff)
{
	int strnum = pcre_get_stringnumber(re->compiled_re, (const char *)name);
	return pcre_get_named_substring(
				re->compiled_re,
				pquery->subject,
				pquery->ovector,
				pquery->match_num,
				(const char *)name,
				(const char **)buff,
			);
}


#endif
