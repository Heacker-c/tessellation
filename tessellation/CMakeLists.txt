set(target tessellation)
set( tessellation_SOURCES
	main.cpp
	scenebezcurve.cpp
	scenebezcurve-debug.cpp
	scenesimpletessmore.cpp
	scenesimpletess.cpp
	scenetessteapot.cpp
	scenetessteapotdepth.cpp )

add_executable( ${target} ${tessellation_SOURCES} )

target_compile_definitions(${target}
		PRIVATE
		GLFW_INCLUDE_NONE
		)

target_link_libraries( ${target}
		PRIVATE
		ingredients
		glfw
		${OPENGL_gl_LIBRARY}
		)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shader DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/esshader DESTINATION ${CMAKE_CURRENT_BINARY_DIR})