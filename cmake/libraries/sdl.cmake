if(NOT BUILD_CLIENT)
    return()
endif()

set(INTERNAL_SDL_DIR ${SRC_DIR}/thirdparty/sdl3/3.2.24)

set(SDL3_INCLUDE_DIRS
	${INTERNAL_SDL_DIR}/include/
)

set(SDL3_LIBRARIES
    ${SRC_DIR}/thirdparty/libs/macos/libSDL3.dylib
)

list(APPEND CLIENT_INCLUDE_DIRS ${SDL3_INCLUDE_DIRS})
list(APPEND CLIENT_LIBRARIES    ${SDL3_LIBRARIES})
