#ifndef Q_SDT_H_
#define Q_SDT_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef FILE		 *qSDTInPipe;
typedef uint64_t	 qSDTCurrent, qSDTExpect;
typedef uint8_t		 *qSDTImmCode;

typedef struct {
	qSDTInPipe		input_channel;	
	qSDTCurrent		current_tag;
	qSDTExpect		expect_tag;
	qSDTImmCode		inter_gen;
} qSDT;

static inline qSDT*
new_sdt(qSDTInPipe inch)
{
	qSDT	*sdt	= calloc(1, sizeof(qSDT));
	sdt->input_channel = inch;
	return sdt;
}





#endif
