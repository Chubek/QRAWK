#ifndef Q_THREAD_H_
#define Q_THREAD_H_

#include <stdlib.h>

#include "import-glib.h"

typedef GThread				*qThreadExec;
typedef GThreadFunc			qThreadFn;
typedef GMutex				*qMutex;
typedef GRWLock				*qRWLock;
typedef gpointer			qThreadData;
typedef const gchar			*qThreadName;

typedef struct {
	qThreadExec		exec;
	qThreadFn		func;
	qThreadData		data, retval;
	qThreadName		name;
} qThread;

static inline qThread*
new_thread(void)
{
	qThread 	*thrd;
	thrd		=  calloc(1, sizeof(qThread));
	return thrd;
}

static inline void
free_thread(qThread *thrd)
{
	free(thrd);
}

static inline void
init_thread(qThread *thrd)
{
	thrd->exec =	g_thread_new(
					q->name,
					q->func,
					q->data,
				);
}


static inline qThreadExec
thread_self(qThread *thrd)
{
	return (qThreadExec)g_thread_self();
}

static inline void
thread_exit(qThread *thrd)
{
	g_thread_exit(thrd->retval);
}

static inline void
thread_join(qThread *thrd)
{
	thrd->retval		=	g_thread_join(thrd->exec);
}

static inline void
thread_yield(qThread *thrd)
{
	g_thread_yield();
}

static inline qMutex
new_mutex(void)
{
	qMutex	mutex;
	g_mutex_init(mutex);
	return mutex;
}

static inline void
clear_mutex(qMutex mutex)
{
	g_mutex_clear(mutex);
}

static inline void
lock_mutex(qMutex mutex)
{
	g_mutex_lock(mutex);
}

static inline void
unlock_mutex(qMutex mutex)
{
	g_mutex_unlock(mutex);
}

static inline qRWLock
new_rwlock(void)
{
	qRWLock rwl;
	g_rw_lock_init(rwl);
	return rwl;
}

static inline void
clear_rwlock(qRWLock rwl)
{
	g_rw_lock_clear(rwl);
}


static inline void
write_rwlock(qRWLock rwl)
{
	g_rw_loc_writer_lock(rwl);
}

static inline void
write_rwunlock(qRWLock rwl)
{
	g_rw_lock_writer_unlock(rwl)
}

static inline void
read_rwlock(qRWLock rwl)
{
	g_rw_lock_reader_lock(rwl);
}


static inline void
read_rwunlock(qRWLock rwl)
{
	g_rw_lock_reader_unlock(rwl);
}
















#endif
