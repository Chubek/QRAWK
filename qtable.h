#ifndef QTABLE_H_
#define QTABLE_H_

#include <glib-2.0/glib.h>



typedef GHashTable	*qHTable;
typedef GList		*qHList;
typedef gboolean	qHResult;
typedef gpointer	qHPointer;
typedef gconstptr	qHConstP;


static inline qHTable
new_table(void)
{
	return (qHTable)g_hash_table_new(g_str_hash, g_str_equal);	
}

static inline void
free_table(qHTable tbl)
{
	g_hash_table_destroy(tbl);
}

static inline qHResult
insert_into_table(qHTable tbl, void *key, void *item)
{
	return (qHResult)g_hash_table_insert(tbl, (qHConstP)key, (qHConstP)item);
}

static inline qHResult
remove_from_table(qHTable tbl, void *key)
{
	return (qHResult)g_hash_table_remove(tbl, (qHConstP)key);
}

static inline qHResult
check_table_contains(qHTable tbl, void *key)
{
	return (qHResult)g_hash_table_contains(tbl, (qHConstP)key);
}


static inline qHList
get_table_keys(qHTable tbl)
{
	return (qHList)g_hash_table_key(tbl);
}

static inline qHList
get_table_values(qHTable tbl)
{
	return (qHList)g_hash_table_values(tbl);
}


static inline qHPointer
look_up_table(qHTable tbl, void *key)
{
	return (qHPointer)g_hash_table_lookup(tbl, (qHConstP)key);
}



#endif
