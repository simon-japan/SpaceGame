cmake_minimum_required(VERSION 3.3)
project(SpaceGame)

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

set(SOURCE_FILES src/View/LTexture.cpp src/View/LTexture.h src/Model/Tile.cpp src/Model/Tile.h src/Model/Character.cpp src/Model/Character.h src/Model/Geometry.cpp src/Model/Geometry.h src/Model/Level.cpp src/Model/Level.h src/View/Renderer.cpp src/View/Renderer.h src/View/Sprite.cpp src/View/Sprite.h src/View/SpriteRepository.cpp src/View/SpriteRepository.h src/Serialization/SpriteLoader.cpp src/Serialization/SpriteLoader.h src/View/TextureRepository.cpp src/View/TextureRepository.h src/Serialization/XmlDomErrorHandler.cpp src/Serialization/XmlDomErrorHandler.h src/Serialization/XmlDOMDocument.cpp src/Serialization/XmlDOMDocument.h src/Serialization/LevelLoader.cpp src/Serialization/LevelLoader.h src/Model/TileType.cpp src/Model/TileType.h src/View/Clip.cpp src/View/Clip.h src/View/CharacterRenderer.cpp src/View/CharacterRenderer.h src/Model/GameObject.cpp src/Model/GameObject.h src/View/GameObjectRenderer.cpp src/View/GameObjectRenderer.h src/View/GameObjectRendererFactory.cpp src/View/GameObjectRendererFactory.h src/View/CharacterRendererFactory.cpp src/View/CharacterRendererFactory.h src/View/TileRenderer.cpp src/View/TileRenderer.h src/View/TileRendererFactory.cpp src/View/TileRendererFactory.h)

add_library(SpaceGameLib STATIC ${SOURCE_FILES})

target_link_libraries(
        SpaceGameLib
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${SDL2_TTF_LIBRARY}
        ${SDLMIXER_LIBRARY}
        ${XercesC_LIBRARIES}
        )

add_executable(SpaceGame src/main.cpp)

find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(BoostTest src/main.cpp)
target_link_libraries(BoostTest ${Boost_LIBRARIES})

add_subdirectory(SpaceGame_tests)

add_subdirectory(configuration)

target_link_libraries(SpaceGame SpaceGameLib)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/configuration/ DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/configuration)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/ DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources)
