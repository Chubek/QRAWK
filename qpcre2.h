#ifndef Q_PCRE2_H_
#define Q_PCRE2_H_

#include <stdint.h>
#include <stdlib.h>

#include "import-pcre2.h"

typedef pcre2_code		*qPCRE2Code;
typedef pcre2_match_data	*qPCRE2Match;
typedef pcre2_general_context	*qPCRE2GenCtx;
typedef pcre2_match_context	*qPCRE2MatchCtx;
typedef int32_t			qPCRE2Opts;
typedef PCRE2_SPTR		qPCRE2Pattern;
typedef PCRE2_SIZE		qPCRE2Size;


typedef struct {
	qPCRE2Code		re_compiled;
	qPCRE2Match		matched;
	qPCRE2GenCtx		gen_ctx;
	qPCRE2MatchCtx		match_ctx;
	qPCRE2Opts		options;
	qPCRE2Pattern		raw_pattern;
	qPCRE2Size		length;
} qPCRE2Query;

static inline void qPCRE2Query*
new_pcre2_query(void)
{

}










#endif
