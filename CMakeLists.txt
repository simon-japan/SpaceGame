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

set(SOURCE_FILES src/main.cpp src/View/LTexture.cpp src/View/LTexture.h src/Model/Tile.cpp src/Model/Tile.h src/Model/Dot.cpp src/Model/Dot.h src/Model/Geometry.cpp src/Model/Geometry.h src/Model/Level.cpp src/Model/Level.h src/View/SpriteSheet.cpp src/View/SpriteSheet.h src/View/Renderer.cpp src/View/Renderer.h src/View/Sprite.cpp src/View/Sprite.h src/View/SpriteRepository.cpp src/View/SpriteRepository.h)
add_executable(sdtTest ${SOURCE_FILES})

target_link_libraries(sdtTest
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${SDL2_TTF_LIBRARY}
        ${SDLMIXER_LIBRARY}
        )

