#ifndef Q_GRAPH_H_
#define Q_GRAPH_H_


#include "import-glib.h"


typedef GList 			*qGraph;
typedef GVariant		*qGraphRel;
typedef GFunc			qGraphFn;
typedef gpointer		qGraphItem, qGraphData;


static inline qGraph
new_graph(void)
{
	return (qGraph)g_list_alloc();
}

static inline void
free_graph(qGraph grph)
{
	g_list_free(grph);
}


static inline qGraphRel
new_graph_rel(qGraphItem item1, qGraphItem item2)
{
	qGraphRel rel;
	rel 		=  g_variant_new("(&&)", item1, item2);
	return rel;
}

static inline void
free_graph_rel(qGraphRel rel)
{
	g_free(rel);
}

static inline qGraph
insert_graph_rel(qGraph grph, qGraphRel rel)
{
	return	(qGraph)g_list_append(grph, (qGraphItem)rel);
}

static inline qGraph
remove_graph_rel(qGraph grph, qGraphRel rel)
{
	return (qGraph)g_list_remove(qrph, (gconstpointer)rel);
}

static inline void
apply_function_to_graph(qGraph grph, qGraphFn apply, qGraphData data)
{
	g_list_foreach(grph, apply, data);
}





#endif
