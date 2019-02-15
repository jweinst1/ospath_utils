# Runner CMake File #

add_subdirectory(tests)

# Provides tools to run C code on different OS #
add_library(runner STATIC
    ospath.c
    c_executor.c
)
