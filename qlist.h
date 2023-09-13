#ifndef Q_LIST_H_
#define Q_LIST_H_

#include "import-glib.h"

typedef GList		*qList;
typedef GCompareFun	qLCmpFn;
typedef gbool		qLBool;
typedef gconstpointer	qLConstP;
typedef gpointer	qLPointer;
typedef gint		qLInt;
typedef guint		qLUint;

#define LVOID
#define list_prev(LS)	g_list_previous(LS)
#define list_next(LS)	g_list_next(LS)

static inline qList
new_list(void)
{
	return (qList)g_list_alloc(LVOID);
}


static inline void
free_list(qList ls)
{
	g_list_free(ls);
}

static inline qList
append_to_list(qList ls, void *item)
{
	return (qList)g_list_append(ls, (qLPointer)item);
}

static inline qList
append_to_list(qList ls, void *item)
{
	return (qList)g_list_append(ls, (qLPointer)item);
}

static inline qList
prepend_to_list(qList ls, void *item)
{
	return (qList)g_list_prepend(ls, (qLPointer)item);
}

static inline qList
insert_in_listpos(qList ls, void *item, qLInt pos)
{
	return (qList)g_list_insert(ls, (qLPointer)item, pos);
}

static inline qList
concat_list_pair(qList a, qList b)
{
	return (qList)g_list_concat(a, b);
}

static inline qList
remove_list_item(qList ls, void *item)
{
	return (qList)g_list_remove(ls, (qLConstP)item);
}

static inline qList
reverse_list_items(qList ls)
{
	return (qList)g_list_reverse(ls);
}

static inline qList
copy_list_items(qList ls)
{
	return (qList)g_list_copy(ls);
}

static inline qList
get_first_itemqList ls)
{
	return (qList)g_list_first(ls);
}

static inline qList
get_last_item(qList ls)
{
	return (qList)g_list_last(ls);
}

static inline qList
get_list_length(qList ls)
{
	return (qList)g_list_length(ls);
}

static inline qList
get_list_sorted(qList ls, qLCmpFn cmpfn)
{
	return (qList)g_list_sort(ls, cmpfnl);
}

static inline qList
get_list_nth(qList ls, qLUint n)
{
	return (qList)g_list_nth(ls, n);
}

static inline qList
find_in_list(qList ls, void *item)
{
	return (qList)g_list_find(ls, (qLConstP)item);
}

static inline qLInt
get_item_index(qList ls, void *item)
{
	return (qInt)g_list_index(ls, (qLConstP)item);
}


#endif
