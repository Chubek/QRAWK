#ifndef Q_REGEX_H_
#define Q_REGEX_H_

#include <pcre.h>
#include <stdint.h>
#include <stdlib.h>

#define CCRE_FAIL		0xFF
#define CCRE_SUCCESS		0x80
#define MARK_STAT_FAIL(STAT)		((STAT << 32) | CCRE_FAIL)
#define MARK_STATS_SUCCESS(STAT)	((STAT << 32) | CCRE_SUCCESS)
#define IS_STAT_FAIL(STAT)		((STAT & 0xFF) == CCRE_FAIL)
#define IS_STAT_SUCCESS(STAT)		((STAT & 0xFF) == CCRE_SUCCESS)

typedef pcre		*qRegex;
typedef uint8_t		*qRePattern;
typedef int32_t		qReOpts;
typedef uint64_t 	qCCStat;

typedef enum {
	ReplaceSubstr,
	MatchSubStr,
	GetSubstr,
} qReAction;

typedef struct {
	qRegex		compiled_re;
	qRePattern	raw_pattern;
	qReOpts		re_opts;
	qReAction	re_action;
} qRe;

static inline qRe*
new_regex(qRePattern raw_pattern, qReAction action)
{
	qRe	*re		= calloc(1, sizeof(qRe));
	re->raw_pattern 	= raw_pattern;
	re->re_action  		= action;
	return re;
}

static inline void
free_re(qRe *re)
{
	free(re);
}

static inline qCCStat
compile_re(qRe *re)
{
	int error_code, error_offset;
	char *error;
	re->compiled_re 	= pre_compile2(
						re->raw_pattern,
						PCRE_CONFIG_UTF8,
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





#endif
