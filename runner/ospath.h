#ifndef RUNNER_OSPATH_H
#define RUNNER_OSPATH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/**
 * This file provides utilities to form pathnames
 * on both windows or unix
 */

#ifdef WIN32_UTF16_PATHNAMES

typedef wchar_t ospath_char_t;
#  define OSPATH_CONSTANT(val)		L##val
#  define LOSPATH_SEP_CHAR		L'\\'
#  define LOSPATH_SEP_STR		L"\\"
#  define LOSPATH_DIVIDE_CHAR		L';'
#  define LOSPATH_DIVIDE_STR		L";"
#  define ospath_strlen(ptr)		(wcslen(ptr))
#  define ospath_are_equal(p1, p2)	(0 == wcscmp((p1), (p2)))
#  define ospath_remove _wremove
#else // !WIN32_UTF16_PATHNAMES

typedef char ospath_char_t;
#  define OSPATH_CONSTANT(val)		val
#  define ospath_strlen(ptr)		(strlen(ptr))
#  define ospath_are_equal(p1, p2)	(0 == strcmp((p1), (p2)))
#  define ospath_remove remove
#endif // WIN32_UTF16_PATHNAMES

// Main declares
#ifdef WIN32_UTF16_PATHNAMES
#  define ospath_main_func int wmain(int argn, const wchar_t * const *argv)
#else
#  define ospath_main_func int main(int argc, const char * const *argv)
#endif // WIN32_UTF16_PATHNAMES

// popen defines
#ifdef _WIN32
#  ifdef WIN32_UTF16_PATHNAMES
#     define ospath_popen _wpopen
#  else // !WIN32_UTF16_PATHNAMES
#     define ospath_popen _popen
#  endif // WIN32_UTF16_PATHNAMES
#else // !_WIN32
#  define ospath_popen popen
#endif // _WIN32

// fopen defines
#ifdef WIN32_UTF16_PATHNAMES
#   define ospath_fopen _wfopen
#else
#   define ospath_fopen fopen
#endif

// Wraps popen calls in appropiate ospath chars.
// evaluates to a FILE*
#define ospath_call_popen(cmd, mode) (ospath_popen(OSPATH_CONSTANT(cmd), OSPATH_CONSTANT(mode)))

// Cross platform functions
extern void ospath_gen_random(ospath_char_t* buf, size_t n);




#endif
