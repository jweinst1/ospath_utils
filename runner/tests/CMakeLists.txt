# Tests for Runner #

include_directories(${PROJECT_SOURCE_DIR}/runner
                    ${PROJECT_SOURCE_DIR}/utils)

# OS Path Tests #
add_executable(test_ospath test_ospath.c ${PROJECT_SOURCE_DIR}/runner/ospath.c)
add_test(test_ospath test_ospath)

# C Executor Tests #
add_executable(test_c_executor test_c_executor.c)
target_link_libraries(test_c_executor test_helpers runner)
add_test(test_c_executor test_c_executor)
