#ifndef Q_ENTITY_H_
#define Q_ENTITY_H_


#include <stdint.h>
#include <stdbool.h>

#define ENTITY_LIVES		1
#define ENTITY_DIES		0

#define ENTITY_INTEGER		1
#define ENTITY_REAL		2
#define ENTITY_STRING		3
#define ENTITY_BRE		4
#define ENTITY_PCRE		5
#define ENTITY_GRAMMAR		6
#define ENTITY_FUNCTION		7
#define ENTITY_BUILTIN		8


typedef uint8_t			qEntityType, qEntityLife, qEntityInMem;
typedef struct {
	uintptr_t		inmem 	: 56;
	uintptr_t		lives	: 1;
	uintptr_t		type	: 4;		
} qEntity;

static inline qEntity*
entity_new(qEntityInMem inmem, qEntityType type)
{
	qEntity		*ent	= calloc(1, sizeof(qEntity));
	ent->inmem		= inmem;
	ent->type		= type;
	ent->lives		= ENTITY_LIVES;
	return ent;
}


static inline void
entity_free(qEntity *ent)
{
	free((void*)entity->inmem); free(ent);
}

static inline void
entity_change_type(qEntity *ent, qEntityType new_type)
{
	ent->type	=	new_type;
}

static inline void
entity_


static inline void
entity_mark_death(qEntity *ent)
{
	ent->lives 	= ENTITY_DIES;
}

static inline bool
entity_attempt_kill(qEntity *ent)
{
	if (ent->lives == ENTITY_DIES) {
		entity_free(ent);
		return true;
	}
	return false;
}






#endif
