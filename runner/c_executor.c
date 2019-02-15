#include "c_executor.h"

// The command on gcc to write c-code via stdin
const ospath_char_t* GCC_RUN_CMD = OSPATH_CONSTANT("gcc -x c -");
// mode to pass to popen
static const ospath_char_t* GCC_RUN_CMD_MODE = OSPATH_CONSTANT("w");

static const ospath_char_t* RESULT_RUN_MODE = OSPATH_CONSTANT("r");

int c_executor_compile_run(const char* source_code)
{
	FILE* proc;
	proc = ospath_popen(GCC_RUN_CMD, GCC_RUN_CMD_MODE);
	fwrite(source_code, sizeof(char), strlen(source_code), proc);
	if(ferror(proc))
	{
		fprintf(stderr, "Compile Error: Cannot compile C code:%s\n", source_code);
		return 0;
	}
	if(pclose(proc) == -1)
	{
		fprintf(stderr, "Compile IO Error: Encountered error closing gcc process.\n");
        return 0;
    }
#ifdef WIN32_UTF16_PATHNAMES
    _wsystem(ospath_gcc_out);
#else // !WIN32_UTF16_PATHNAMES
    system(ospath_gcc_out);
#endif // WIN32_UTF16_PATHNAMES
    ospath_remove(ospath_gcc_out);
	return 1;
}

int c_executor_execute(const char* source_code, char* result, size_t max)
{
	FILE* proc;
	FILE* rproc;
	char rline[1024];
	const char* output_end;
	char* output_writer = result;
	output_end = result + max;
	proc = ospath_popen(GCC_RUN_CMD, GCC_RUN_CMD_MODE);
	fwrite(source_code, sizeof(char), strlen(source_code), proc);
	if(ferror(proc))
	{
		fprintf(stderr, "Compile Error: Cannot compile C code:%s\n", source_code);
		return 0;
	}
	if(pclose(proc) == -1)
	{
		fprintf(stderr, "Compile IO Error: Encountered error closing gcc process.\n");
        return 0;
    }
    rproc = ospath_popen(ospath_gcc_out, RESULT_RUN_MODE);
    // writes output
    while(fgets(rline, sizeof(rline), rproc) != NULL && output_writer < output_end)
    {
    	strncpy(output_writer, rline, sizeof(rline));
    	output_writer += sizeof(rline);
    }

    if(ferror(rproc))
    {
    	fprintf(stderr, "Run Error: Cannot read stdout of C process.\n");
    	return 0;
    }

    if(pclose(rproc) == -1)
    {
    	fprintf(stderr, "Run IO Error: Cannot close C reuslt process.\n");
    	return 0;
    }
	ospath_remove(ospath_gcc_out);
	return 1;
}
