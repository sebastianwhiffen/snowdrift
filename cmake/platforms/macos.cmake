if(NOT APPLE)
    return()
endif()

option(BUILD_MACOS_APP "Deploy as a macOS .app" ON)


if(BUILD_MACOS_APP)
    set(CLIENT_EXECUTABLE_OPTIONS MACOSX_BUNDLE)
    # list(APPEND POST_CONFIGURE_FUNCTIONS finish_macos_app)
endif()



