set(EXE_NAME marble-madness-3d)

# Target
set(SRC_FILES
    game.cpp
    main.cpp
)
set(LIBRARIES
    kernel
    renderer
    resources
    physics
)

add_executable(${EXE_NAME} ${SRC_FILES})

# Link libraries
find_package(SDL REQUIRED)

include_directories(${SDL_INCLUDE_DIR})
target_link_libraries(${EXE_NAME} ${LIBRARIES})

add_subdirectory(engine)
