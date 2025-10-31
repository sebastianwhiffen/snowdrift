
if(NOT BUILD_CLIENT)
    return()
endif()

set(CLIENT_SOURCES
	${SRC_DIR}/sys/sys_main.c 
	${SRC_DIR}/common/common.c
)


list(APPEND CLIENT_BINARY_SOURCES
	${CLIENT_SOURCES}
)

add_executable(snowdrift ${CLIENT_BINARY_SOURCES})

target_include_directories(snowdrift PRIVATE ${CLIENT_INCLUDE_DIRS})
target_link_libraries(snowdrift PRIVATE ${CLIENT_LIBRARIES})

set_target_properties(snowdrift PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
)
