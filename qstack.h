#ifndef Q_STACK_H_
#define Q_STACK_H_

#include <stdlib.h>

#include "import-glib.h"

typedef GQueue			*qStack;
typedef gpointer		qStackData;

static inline qStack*
new_stack(void)
{
	qStack 	*qs	= calloc(1, sizeof(qStack));
	qs		= g_queue_new();
	g_queue_init(qs);
	return qs;
}

static inline void
fee_stack(qStack *qs)
{
	g_queue_free(qs);
}

static inline void
push_stack(qStack *qs, void *data)
{
	g_queue_push_head(qs, (qStackData)data);
}

static inline void*
pop_stack(qStack *qs)
{
	return (void *)g_queue_pop_head(qs);
}












#endif
