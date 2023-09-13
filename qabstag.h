#ifndef Q_ABSTAG_H_
#define Q_ABSTAG_H_

#include <stdint.h>

#define LVALUE		(1 << 1) 
#define RVALUE		(1 << 2)
#define IDENT		(1 << 3)
#define UNARY		(1 << 4)
#define BINARY		(1 << 5)
#define EXPR		(1 << 6)
#define STMT		(1 << 7)
#define ACCESS		(1 << 8)
#define PREFIX		(1 << 9)
#define SUFFIX		(1 << 10)
#define KEYWORD		(1 << 11)
#define BUILTIN		(1 << 12)
#define FUNCTION	(1 << 13)
#define VARIABLE	(1 << 14)
#define ARRAY		(1 << 15)
#define LITERAL		(1 << 16)
#define INTEGER		(1 << 17)
#define REAL		(1 << 18)
#define STRING		(1 << 19)
#define PATTERN		(1 << 20)
#define PCREMATCH	(1 << 21)
#define PCRESUB		(1 << 22)
#define PCRETR		(1 << 23)
#define BRE		(1 << 24)
#define ACTION		(1 << 25)
#define FILED		(1 << 26)
#define SPECIAL		(1 << 27)
#define BEGIN		(1 << 28)
#define END		(1 << 29)
#define OPERATOR	(1 << 30)
#define TERNARY		(1 << 31)
#define PIPE		(1 << 32)
#define STDIN		(1 << 33)
#define STDOUT		(1 << 34)
#define STDERR		(1 << 35)
#define INFILE		(1 << 36)
#define ENVIRON		(1 << 37)
#define SIGIL		(1 << 38)
#define NTH		(1 << 39)
#define CALL		(1 << 40)
#define QUOTE		(1 << 41)
#define UNQUOTE		(1 << 42)
#define EXEC		(1 << 43)
#define EVAL		(1 << 44)

typedef uint64_t abstag_t;








#endif
