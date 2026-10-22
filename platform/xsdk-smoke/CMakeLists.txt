cmake_minimum_required(VERSION 3.25)
project(x360_capture_sdk_smoke C)

add_executable(x360_capture_sdk_smoke main.c)
set_target_properties(x360_capture_sdk_smoke PROPERTIES C_STANDARD 17 C_EXTENSIONS ON)
target_compile_options(x360_capture_sdk_smoke PRIVATE -Wall -Wextra -Werror)
xsdk_add_xex(x360_capture_sdk_smoke)
