cmake_minimum_required(VERSION 3.15)
project(minecraft)
set(CMAKE_CXX_STANDARD 14)
#-path-
set(SDL2_INC_DIR  D:/thirdlibary/SDL/include)
set(SDL2_LIB_DIR  D:/thirdlibary/SDL/lib)
set(GLM_INC_DIR  D:/thirdlibary/glm/include)

#-SDL-
include_directories(${SDL2_INC_DIR})
link_directories(${SDL2_LIB_DIR})
link_libraries(
        SDL2
        SDL2main
        SDL2_image)
#-glm-
include_directories(${GLM_INC_DIR})


add_executable(minecraft
        main.cpp
        World/World.cpp
        World/World.h
        GL/gl_imp.h
        defination.h
        Block/Chunk.cpp
        Block/Chunk.h)
target_link_libraries(minecraft
        SDL2
        SDL2main
        SDL2_image)
