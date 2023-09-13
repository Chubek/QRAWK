#ifndef Q_SDT_H_
#define Q_SDT_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "qsdt-tags.inc"

typedef uint64_t	 qSDTCurrent, qSDTExpect, qSDTTag;
typedef uint8_t		 *qSDTImmCode;
typedef qSDTTag		 (*nexttagfn_t)(void);

typedef struct {
	qSDTCurrent		current_tag;
	qSDTExpect		expect_tag;
	qSDTImmCode		inter_gen;
	nexttagfn_t		nextfn;
} qSDT;

static inline qSDT*
new_sdt(nexttagfn_t nextfn)
{
	qSDT	*sdt	= calloc(1, sizeof(qSDT));
	sdt->nextfn	= nextfn;
	return sdt;
}

static inline void
free_sdt(qSDT *sdt)
{
	free(sdt);
}





#endif
