# Own-title GPU readback probe based on xSDK's MIT-licensed triangle sample.
cmake_minimum_required(VERSION 3.25)
project(x360_capture_gpu_probe C)
add_executable(x360_capture_gpu_probe main.c)
set_target_properties(x360_capture_gpu_probe PROPERTIES C_STANDARD 17 C_EXTENSIONS ON)
target_compile_options(x360_capture_gpu_probe PRIVATE -Wall -Wextra -Werror)
xsdk_add_shaders(x360_capture_gpu_probe triangle.vert triangle.frag)
xsdk_add_xex(x360_capture_gpu_probe)
