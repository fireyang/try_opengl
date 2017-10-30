

cmake_minimum_required (VERSION 3.0)

set(APP_TARGET Test1)
project(Test1)

# link_libraries(glfw)

# find_package(glfw3 REQUIRED)
# include_directories(${GLFW_INCLUDE_DIRS})
# link_libraries(${GLFW_LIBRARY_DIRS})
link_libraries(glfw)

include_directories("deps")

# find_package(glfw3 REQUIRED)

# set(CMAKE_CXX_FLAGS "-lGL -lGLU -lglfw3 -lX11 -lXrandr -lpthread -lXi")
set(GLAD "deps/glad.c" "deps/glad/glad.h")

include_directories (
    include/
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# add_library(GLAD SHARED "deps/glad.c" "deps/glad/glad.h")

add_executable(Test1 "src/test1.cpp" ${GLAD})
add_executable(hello_triangle "src/hello_triangle.cpp" ${GLAD})
add_executable(shaders_interpolation "src/shaders_interpolation.cpp" ${GLAD})
add_executable(shaders_class "include/shader_s.h" "src/shaders_class.cpp" ${GLAD})

# file(GLOB_RECURSE source_files ${PROJECT_SOURCE_DIR}/src/*)
# add_executable(${APP_TARGET} ${source_files})

# target_link_libraries(
#     ${APP_TARGET}
#     glfw
#     GLAD
#     # ${OPENGL_LIBRARIES}
#     ${GLEW_LIBRARIES}
#     # ${EXTRA_LIBS}
# )
