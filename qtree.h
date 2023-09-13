#ifndef Q_TREE_H_
#define Q_TREE_H_

#include "import-glib.h"

typedef GTree		*qTree;
typedef GTreeNode	*qTreeNode;
typedef GList		*qTList;
typedef GCompareFunc	qTCmpFn;
typedef gbool		qTBool;
typedef gpointer	qTPointer;
typedef gconstpointer	qTConstP;


static inline qTree
new_qtree(qTCmpFn cmpfn)
{
	return (qTree)g_tree_new(cmpfn);
}

static inline void
free_qtree(qTree tree)
{
	g_tree_destroy(tree);
}

static inline qTreeNode
insert_into_tree(qTree tree, void *key, void *value)
{
	return (qTreeNode)g_tree_insert_node(tree, (qTConstP)key, (qTConstP)value);
}

static inline qTBool
remove_from_tree(qTree tree, void *key)
{
	return (qTBool)g_tree_remove(tree, (qTConstP)key);
}

static inline qTreeNode
get_first_node(qTree tree)
{
	return (qTreeNode)g_node_first(tree);
}

static inline qTreeNode
get_last_node(qTree tree)
{
	return (qTreeNode)g_node_last(tree);
}

static inline qTreeNode
get_next__node(qTree tree)
{
	return (qTreeNode)g_node_next(tree);
}

static inline qTreeNode
get_prev_node(qTree tree)
{
	return (qTreeNode)g_node_previous(tree);
}

static inline qTPointer
lookup_in_tree(qTree tree, void *key)
{
	return (qTPointer)g_tree_lookup(tree, (qTConstP)key);
}


#endif
