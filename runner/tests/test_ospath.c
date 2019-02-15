#include "test_failures.h"
#include "ospath.h"



void test_ospath_gen_random(void)
{
	static ospath_char_t path[5];
	static ospath_char_t path2[5];
	ospath_gen_random(path, 5);
	ospath_gen_random(path2, 5);
	TEST_FAIL_CHECK(!(ospath_are_equal(path, path2)));
}


int main(int argc, char const *argv[])
{
	test_ospath_gen_random();
	TEST_FAIL_RETURN
}
