#ifndef Q_STRING_H_
#define Q_STRING_H_

#include <glib-2.0/glib.h>

typedef GString		*qString;
typedef const gchar	*qCharP;
typedef gbool		qStrBool;
typedef gpointer	qStrPointer;
typedef gconstpointer	qStrConstP;
typedef gsize		qStrSize;
typedef gssize		qStrSSzie;

#define string_printf(STR, FMT, ...) 			\
	g_string_printf(STR, FMT, __VA_ARGS__)
#define string_printf_append(STR, FMT, ...) 		\
	g_string_append_printf(STR, FMT, __VA_ARGS__)


static inline qString
new_string(unsigned char *chars)
{
	return (qString)g_string_new((qCharP)chars);
}

static inline void
free_string(qString str)
{
	g_string_free(str);
}

static inline qStrBool
check_str_equals(qString a, qString b)
{
	return (qStrBool)g_string_equal(a, b);
}

static inline qString
assign_str_to(qString lval, qString rval)
{
	return (qString)g_string_assign(lval, rval);
}

static inline qString
truncate_str_to(qString str, qStrSize newsize)
{
	return (qString)g_string_truncate(str, newsize);
}

static inline qString
append_to_str(qString str, unsigned char *appendage)
{
	return (qString)g_string_append(str, (qCharP)appendage);
}

static inline qString
prepend_to_str(qString str, unsigned char *prependage)
{
	return (qString)g_string_prepend(str, (qCharP)prependage);
}

static inline qString
insert_at_strpos(qString str, unsigned char *addage, qStrSSize pos)
{
	return (qString)g_string_insert(str, pos, (qCharP)addage);
}

static inline qString
overwrite_at_strpos(qString str, unsigned char *overwrite, qStrSize pos)
{
	return (qString)g_string_overwrite(str, pos, (qCharP)overwrite);
}

static inline qString
str_to_upper(qString str)
{
	return (qString)g_string_ascii_up(str);
}

static inline qString
str_to_lower(qString str)
{
	return (qString)g_string_ascii_down(str);
}

