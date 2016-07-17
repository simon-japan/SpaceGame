cmake_minimum_required(VERSION 3.3)
project(sdtTest)

# use FindSDL2.cmake
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED >=2.0.0)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(xercesc)

include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${SDLMIXER_INCLUDE_DIR}
        ${XercesC_INCLUDE_DIRS}
)

set(SOURCE_FILES src/View/LTexture.cpp src/View/LTexture.h src/Model/Tile.cpp src/Model/Tile.h src/Model/Dot.cpp src/Model/Dot.h src/Model/Geometry.cpp src/Model/Geometry.h src/Model/Level.cpp src/Model/Level.h src/View/Renderer.cpp src/View/Renderer.h src/View/Sprite.cpp src/View/Sprite.h src/View/SpriteRepository.cpp src/View/SpriteRepository.h src/Serialization/SpriteLoader.cpp src/Serialization/SpriteLoader.h src/View/TextureRepository.cpp src/View/TextureRepository.h src/Serialization/XmlDomErrorHandler.cpp src/Serialization/XmlDomErrorHandler.h src/Serialization/XmlDOMDocument.cpp src/Serialization/XmlDOMDocument.h src/Serialization/LevelLoader.cpp src/Serialization/LevelLoader.h src/Model/TileType.cpp src/Model/TileType.h)

add_library(sdTestLib STATIC ${SOURCE_FILES})

target_link_libraries(
        sdTestLib
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${SDL2_TTF_LIBRARY}
        ${SDLMIXER_LIBRARY}
        ${XercesC_LIBRARIES}
        )

add_executable(sdtTest src/main.cpp)

find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(BoostTest src/main.cpp)
target_link_libraries(BoostTest ${Boost_LIBRARIES})

#add_executable(sprites.xml configuration/sprites.xml)

add_subdirectory(sdtTest_tests)

add_subdirectory(configuration)

target_link_libraries(sdtTest sdTestLib)

# file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/configuration/sprites.xml DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/configuration/)

#add_custom_command(TARGET sdtTest
#        POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/configuration/sprites.xml ${CMAKE_BINARY_DIR}/configuration/)

# Todo: file copy does work, but it goes into the magical clion build directory.
# Maybe what I need to do is pick a specific directory to build into.