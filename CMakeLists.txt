cmake_minimum_required (VERSION 3.0)

set (CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

project (Tessellation)

if(MSVC)
  add_definitions(/DNOMINMAX)
endif()

if(UNIX)
    message(STATUS "Running Linux compiling. Options [GLVND] for modern OpenGL or [LEGACY] for historical OpenGl.")
    message(STATUS "Setting GLVND option.")
    set(OpenGL_GL_PREFERENCE GLVND)
endif()

if(UNIX)
    #find_package( glm CONFIG REQUIRED )
endif()
find_package( OpenGL REQUIRED )

include_directories( ingredients )

add_subdirectory( glm )
add_subdirectory( glfw )
add_subdirectory( ingredients )
add_subdirectory( tessellation )

file(COPY DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
