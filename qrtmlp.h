#ifndef Q_RTMLP_H_
#define Q_RTMLP_H_

#include <glib-2.0/glib.h>
#include <stdarg.h>

#define SKIP_COMMENT_MULTI 		"-c+"
#define SKIP_COMMENT_SINGLE 		"-c1"
#define SCAN_COMMENT_MULTI 		"|c+"
#define SCAN_IDENTIFIER 		"|id+"
#define SCAN_IDENTIFIER_1CHAR 		"|id1"
#define SCAN_IDENTIFIER_NULL 		"|id0"
#define SCAN_SYMBOLS 			"|symc"
#define SCAN_BINARY 			"|symb"
#define SCAN_OCTAL 			"|symo"
#define SCAN_FLOAT			"|symf"
#define SCAN_HEX 			"|symx"
#define SCAN_HEX_DOLLAR 		"|sym$"
#define SCAN_STRING_SQ 			"|str/"
#define SCAN_STRING_DQ 			"|str//"
#define NUMBERS_2_INT 			"->n2i"
#define INT_2_FLOAT 			"->i2f"
#define IDENTIFIER_2_STRING 		"->id2str"
#define CHAR_2_TOKEN 			"->ch2tk"
#define SYMBOL_2_TOKEN 			"->sym2tk"
#define SCOPE_0_FALLBACK 		"s0lup"
#define STORE_INT64			"sti64"
#define SPEC_SENTINEL			NULL

#define SPEC_TO_U64(F, dest) 						\
	do {								\
		char *cpy = F, cc = 0, i = 0;				\
		while ((cc = *cpy++)) {					\
			dest |= cc << i; i += 8;			\
		}							\
	} while (0)

typedef GMarkupParser		*qRLPParser;
typedef GMarkupParseContext	*qRLPParseCtx;
typedef GScanner		*qRLPLexer;
typedef GScannerConfig		*qRLPLexerConf;
typedef GTokenType		*qRLPTokenType;
typedef GTokenValue		*qRLPTokenValue;
typedef GMarkupError		qRLPParseErr;
typedef GErrorType		qRLPLexErr;
typedef gchar			*qRLPExpr, qRLPChar;
typedef gbool			qRLPBool;
typedef gpointer		qRLPPointer;
typedef gconstpointer		qRLPConstP;
typedef guint			qRLPUint;
typedef gint			qRLPInt;
typedef gsize			qRLPSize;
typedef gssize			qRLPSSize;
typedef uint8_t			*qRLPSpec;

typedef struct {
	qRLPLexer		lexer_ctx;
	qRLPLexerConf		lexer_conf;
	qRLPLexErr		last_error;
}

typedef struct {
	qRLPParser		parser_obj;
	qRLPParseCtx		parser_ctx;
	qRLPParseErr		last_error;
}

static qRLPLexerConf
new_lexer_conf(qRLPSpec *spec, ...)
{
	va_list argls;
	va_start(spec, argls);
	uint8_t *spec_str;

	while ((spec_str = *spec++) != SPEC_SENTINEL)
	{
		uint64_t spec_u64 = 0;
		SPEC_TO_U64(spec_str, spec_u64);
	}
}










#endif
