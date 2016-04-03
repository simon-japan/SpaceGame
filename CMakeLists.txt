cmake_minimum_required(VERSION 3.3)
project(sdtTest)

# use FindSDL2.cmake
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED >=2.0.0)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${SDLMIXER_INCLUDE_DIR}
)

set(SOURCE_FILES src/main.cpp src/LTexture.cpp src/LTexture.h src/Tile.cpp src/Tile.h src/Dot.cpp src/Dot.h src/Geometry.cpp src/Geometry.h src/Level.cpp src/Level.h)
add_executable(sdtTest ${SOURCE_FILES})

target_link_libraries(sdtTest
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${SDL2_TTF_LIBRARY}
        ${SDLMIXER_LIBRARY}
        )

