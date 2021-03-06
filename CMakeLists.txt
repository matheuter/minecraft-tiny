cmake_minimum_required(VERSION 3.15)
project(minecraft)
set(CMAKE_CXX_STANDARD 14)
#-path-
set(SDL2_INC_DIR  D:/thirdlibary/SDL/include)
set(SDL2_LIB_DIR  D:/thirdlibary/SDL/lib)
set(GLM_INC_DIR  D:/thirdlibary/glm/include)
set(GLEW_INC_DIR D:/thirdlibary/glew/include)
set(GLEW_LIB_DIR D:/thirdlibary/glew/lib/x64)

#-SDL-
include_directories(${SDL2_INC_DIR})
link_directories(${SDL2_LIB_DIR})
link_libraries(
        SDL2
        SDL2main
        SDL2_image)

#-glm-
include_directories(${GLM_INC_DIR})

#-glew-
include_directories(${GLEW_INC_DIR})
link_directories(${GLEW_LIB_DIR})
link_libraries(opengl32 glew32)

add_executable(minecraft
        main.cpp
        World/World.cpp
        World/World.h
        GL/gl_imp.h
        defination.h
        Block/Chunk.cpp
        Block/Chunk.h
        Block/Block.cpp
        Block/Block.h
        Texture/Texture.cpp
        Texture/Texture.h
        Shader/Shader.cpp
        Shader/Shader.h
        Texture/SkyBox.cpp
        Texture/SkyBox.h
        Model/Mesh.cpp
        Model/Mesh.h
        Model/Attribute.cpp
        Model/Attribute.h
        Model/Model.cpp
        Model/Model.h
        Unity/Unity.cpp
        Unity/Unity.h
        World/Player.cpp
        World/Player.h
        Block/BlockType.cpp
        Block/BlockType.h
        math/Noise.cpp
        math/Noise.h
        Expression/Expression.cpp
        Expression/Expression.h
        GL/gl_error_imp.h
        World/ActionType.cpp
        World/ActionType.h
        Physical/Collision/Collision.cpp
        Physical/Collision/Collision.h
        Physical/Math/Matrix.cpp
        Physical/Math/Matrix.h
        Window.cpp
        Window.h)
target_link_libraries(minecraft
        SDL2
        SDL2main
        SDL2_image
        )
