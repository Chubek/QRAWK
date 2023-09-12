#!/usr/bin/eperl

#ifndef Q_TAGS_H_
#define Q_TAGS_H_

#include <stdint.h>

<:
	open TAGSFILE, "<", "tags.ls";
	$code = 256;
	for (chomp($tag = <TAGSFILE>))	{
		print "#define ", $tag, " ", $code++;
	}
	close TAGSFILE;
:>

typedef uint32_t 	Tag;

#endif
