#ifndef Q_RTMLP_H_
#define Q_RTMLP_H_

#include <glib-2.0/glib.h>
#include <stdarg.h>
#include <string.h>

#define LOOKUP_CASE_SENSITIVE		"+cs"
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

typedef GMarkupParser		*qRLPParser;
typedef GMarkupParseContext	*qRLPParseCtx;
typedef GScanner		*qRLPLexer;
typedef GScannerConfig		*qRLPLexerConf;
typedef GTokenType		*qRLPTokenType;
typedef GTokenValue		*qRLPTokenValue;
typedef GMarkupError		qRLPParseErr;
typedef GErrorType		qRLPLexErr;
typedef gchar			*qRLPExpr, *qRLPCharBuff;
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
} qRLPScan;

typedef struct {
	qRLPParser		parser_obj;
	qRLPParseCtx		parser_ctx;
	qRLPParseErr		last_error;
} qRLPTokenize;

typedef struct {
	gRLPCharBuff		skip_charset;
	gRLPCharBuff		ident_first_charset;
	gRLPCharBuff		ident_nth_charset;
	gRLPCharBuff		comment_cpair_charset;
	qRLSpec			specs_list[MAX_SPEC + 1];
} qRLPLexerSettings;

static qRLPLexerConf
new_lexer_conf(qRLPLexerSettings *settings)
{
	qRLPLexerConf lpconf = calloc(1, sizeof(*qRLPLexerConf));
	qRLPSpec     *spec_ls = &settings->specs_list[0], spec_str;
	
	while ((spec_str = *spec_ls++) != SPEC_SENTINEL)
	{
		if (!strcmp(spec_str, LOOKUP_CASE_SENSITIVE))					lpconf->case_sensitive = true;
		else if (!strcmp(spec_str, SKIP_COMMENT_MULTI))
			lpconf->skip_comment_multi = true;
		else if (!strcmp(spec_str, SKIP_COMMENT_SINGLE))
			lpconf->skip_comment_single = true;
		else if (!strcmp(spec_str, SCAN_IDENTIFIER))
			lpconf->scan_identifier = true;
		else if (!strcmp(spec_str, SCAN_IDENTIFIER_1CHAR))
			lpconf->scan_identifier_1char = true;
		else if (!strcmp(spec_str, SCAN_IDENTIFIER_NULL))
			lpconf->scan_identifier_NULL = true;
		else if (!strcmp(spec_str, SCAN_SYMBOLS))
			lpconf->scan_symbols = true;
		else if (!strcmp(spec_str, SCAN_BINARY))
			lpconf->scan_binary = true;
		else if (!strcmp(spec_str, SCAN_OCTAL))
			lpconf->scan_octal = true;
		else if (!strcmp(spec_str, SCAN_FLOAT))
			lpconf->scan_float = true;
		else if (!strcmp(spec_str, SCAN_HEX))
			lpconf->scan_hex = true;
		else if (!strcmp(spec_str, SCAN_HEX_DOLLAR))
			lpconf->scan_hex_dollar = true;
		else if (!strcmp(spec_str, SCAN_STRING_SQ))
			lpconf->scan_string_sq = true;
		else if (!strcmp(spec_str, SCAN_STRING_DQ))
			lpconf->scan_string_dq = true;
		else if (!strcmp(spec_str, NUMBERS_2_INT))
			lpconf->numbers_2_int = true;
		else if (!strcmp(spec_str, INT_2_FLOAT))
			lpconf->int_2_float = true;
		else if (!strcmp(spec_str, IDENTIFIER_2_STRING))
			lpconf->identifier_2_string = true;
		else if (!strcmp(spec_str, CHAR_2_TOKEN))
			lpconf->char_2_token = true;
		else if (!strcmp(spec_str, SYMBOL_2_TOKEN))
			lpconf->symbol_2_token = true;
		else if (!strcmp(spec_str, SCOPE_0_FALLBACK))
			lpconf->scope_0_fallback = true;
		else if (!strcmp(spec_str, STORE_INT64))
			lpconf->store_int64 = true;
	}

	lpconf->cset_skip_characters     = settings->skip_charset;
	lpconf->cset_identifier_first    = settings->ident_first_charset;
	lpconf->cset_identifier_nth	 = settings->ident_nth_charset;
	lpconf->cpair_comment_single	 = settings->comment_cpair_charset;

	return lpconf;
}

static inline qRLPScan*
new_scanner(qRLPLexerConf lpconf)
{
	qRLPScan	*scn	= calloc(1, sizeof(qRLPScan));
	scn->lexer_conf = lpconf;
}

static inline void
compile_scanner(qRLPScan *scn)
{
	scn->lexer_ctx 		= g_scanner_new(scn->lexer_conf);
}









#endif
