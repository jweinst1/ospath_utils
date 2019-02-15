#include "test_failures.h"
#include "c_executor.h"
#include <string.h>

static const char* C_PROGRAM = ("#include<stdio.h> \n\n int main(int argc, const char * const *argv)"
	                               "{ puts(\"foo\"); }\n");

void test_c_executor_compile_run(void)
{
	TEST_FAIL_CHECK(c_executor_compile_run(C_PROGRAM));
}

void test_c_executor_execute(void)
{
	char out[1024];
	memset(out, 0, sizeof(out));
	size_t max = 1024;
	c_executor_execute(C_PROGRAM, out, max);
	printf("The output of the c code is \n***\n%s***\n", out);
	TEST_FAIL_CHECK(strcmp(out, "foo\n") == 0);
}


int main(int argc, char const *argv[])
{
	test_c_executor_compile_run();
	test_c_executor_execute();
	TEST_FAIL_RETURN
}
