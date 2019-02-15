#ifndef RUNNER_C_EXECUTOR_H
#define RUNNER_C_EXECUTOR_H

#include "ospath.h"

/**
 * This file is used for running and executing generated C code.
 */

// Defines the default gcc output file name
// * Used in instant execution of generated C code
#ifdef _WIN32
#  define ospath_def_gcc_out "a.exe"
#else // !_WIN32
   // In unix simply running executable name doesn't invoke, needs ./
#  define ospath_def_gcc_out "./a.out"
#endif // _WIN32

#define ospath_gcc_out (OSPATH_CONSTANT(ospath_def_gcc_out))

// The command on gcc to write c-code via stdin
extern const ospath_char_t* GCC_RUN_CMD;
/**
 * Compiles the c code, executes, and removes executable.
 * Does not check output.
 */
extern int c_executor_compile_run(const char* source_code);
/**
 * Compiles, runs, and stores the output of the c code executable in result,
 * up to max characters.
 */
extern int c_executor_execute(const char* source_code, char* result, size_t max);

#endif // RUNNER_EXECUTOR_H
