#include "ospath.h"
#include <time.h>

static const ospath_char_t RAND_CHAR_BIN[] = {
	OSPATH_CONSTANT('a'),
	OSPATH_CONSTANT('z'),
	OSPATH_CONSTANT('b'),
	OSPATH_CONSTANT('3'),
	OSPATH_CONSTANT('q'),
	OSPATH_CONSTANT('r'),
	OSPATH_CONSTANT('a'),
	OSPATH_CONSTANT('0'),
	OSPATH_CONSTANT('x'),
	OSPATH_CONSTANT('n'),
	OSPATH_CONSTANT('6'),
	OSPATH_CONSTANT('_'),
	OSPATH_CONSTANT('i'),
	OSPATH_CONSTANT('j')
};

static const size_t RAND_CHAR_SZ = sizeof(RAND_CHAR_BIN);

void ospath_gen_random(ospath_char_t* buf, size_t n)
{

	size_t i;
	srand(time(0));
	for(i=0; i < n; i++)
	{
		buf[i] = RAND_CHAR_BIN[rand() % RAND_CHAR_SZ ];
	}
}
