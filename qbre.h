#ifndef Q_BRE_H_
#define Q_BRE_H_

#include <regex.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>

#define MAX_MATCH	0x1000

typedef regex_t		*qBREgex;
typedef regexmatch_t	*qBREMatch;
typedef uint8_t		*qBREPattern;
typedef int32_t		qBREFlag;

typedef struct {
	qBREgex		compiled_re;
	qBREMatch	re_matches[MAX_MATCH];
	qBREPattern	raw_pattern;
	qBREFlags	flags;
} qBRE;

static inline qBRE*
new_bregex(qBREPattern pattern)
{
	qBRE		*re	= calloc(1, sizeof(qBRE));
	re->pattern = pattern;
}

static inline void
free_bregex(qBRE *re)
{
	free(re);
}

static inline int
compile_bregex(qBRE *re)
{
	return regcomp(re->compiled_re, re->raw_pattern, re->flags);
}

static inline int
matches_bregex(qBRE *re, const uint8_t *query)
{
	return regexec(
			re->compiled_re, 
			(const char*)query, 
			MAX_MATCH,
			re->re_matches,
			0,
		);
}








#endif
