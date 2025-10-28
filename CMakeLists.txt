cmake_minimum_required(VERSION 3.10)
project(snowdrift C)

include(cmake/dirs.cmake)

add_executable(snowdrift ${SRC_DIR}/sys/sys_main.c ${SRC_DIR}/common/common.c)

set_target_properties(snowdrift PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
)
