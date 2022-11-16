set(target ingredients)

set(ingredients_SOURCES
        teapotpatch.cpp
        glutils.cpp
        glslprogram.cpp
        glad/src/glad.c
        trianglemesh.cpp)

add_library(${target} STATIC ${ingredients_SOURCES})

target_include_directories(${target} PUBLIC glad/include)

target_link_libraries(${target} PUBLIC glm)

if( UNIX AND NOT APPLE )
    target_link_libraries(${target} PUBLIC ${CMAKE_DL_LIBS})
endif()


