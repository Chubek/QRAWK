#ifndef Q_ENTITY_H_
#define Q_ENTITY_H_


#include <stdint.h>

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


typedef struct {
	uintptr_t		inmem 	: 56;
	uintptr_t		lives	: 1;
	uintptr_t		type	: 4;		
} qEntity;








#endif
