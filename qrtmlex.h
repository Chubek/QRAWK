#ifndef Q_RTMLEX_H__
#define Q_RTMLEX_H_

#include <glib-2.0/glib.h>
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

typedef GScanner		*qRLEXLexer;
typedef GScannerConfig		*qRLEXLexerConf;
typedef GTokenType		*qRLEXTokenType;
typedef GTokenValue		*qRLEXTokenValue;
typedef GErrorType		qRLEXLexErr;
typedef gchar			*qRLEXExpr, *qRLEXCharBuff;
typedef gbool			qRLEXBool;
typedef gpointer		qRLEXPointer;
typedef gconstpointer		qRLEXConstP;
typedef guint			qRLEXUint;
typedef gint			qRLEXInt;
typedef gsize			qRLEXSize;
typedef gssize			qRLEXSSize;
typedef uint8_t			*qRLEXSpec;

typedef struct {
	qRLEXLexer		lexer_ctx;
	qRLEXLexerConf		lexer_conf;
	qRLEXLexErr		last_error;
} qRLEXScan;

typedef struct {
	gRLEXCharBuff		skip_charset;
	gRLEXCharBuff		ident_first_charset;
	gRLEXCharBuff		ident_nth_charset;
	gRLEXCharBuff		comment_cpair_charset;
	qRLSpec			specs_list[MAX_SPEC + 1];
} qRLEXLexerSettings;

static qRLEXLexerConf
new_lexer_conf(qRLEXLexerSettings *settings)
{
	qRLEXLexerConf lpconf = calloc(1, sizeof(*qRLEXLexerConf));
	qRLEXSpec     *spec_ls = &settings->specs_list[0], spec_str;
	
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

static inline qRLEXScan*
new_scanner(qRLEXLexerConf lpconf)
{
	qRLEXScan	*scn	= calloc(1, sizeof(qRLEXScan));
	scn->lexer_conf = lpconf;
}

static inline void
compile_scanner(qRLEXScan *scn)
{
	scn->lexer_ctx 		= g_scanner_new(scn->lexer_conf);
}

static inline void
free_scanner(qRLEXScan *scn)
{
	g_scanner_destroy(scn->lexer_ctx);
	free(scn->lexer_conf);
	free(scn);
}

static inline void
inputfile_scanner(qRLEXScan *scn, int fd)
{
	g_scanner_input_file(scn->lexer_ctx, fd);
}

static inline void
inputtext_scanner(qRLEXScan *scn, const qRLEXExpr text, gRLEXUint size)
{
	g_scanner_input_text(scn->lexer_ctx, text, size);
}





#endif
