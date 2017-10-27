

cmake_minimum_required (VERSION 3.0)

set(APP_TARGET Test1)
project(Test1)

# link_libraries(glfw)

find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

include_directories("deps")

# find_package(glfw3 REQUIRED)

# set(CMAKE_CXX_FLAGS "-lGL -lGLU -lglfw3 -lX11 -lXrandr -lpthread -lXi")

include_directories (
    include/
)

set(LIBRARY_OUTPUT_PATH, "libs")

add_library(GLAD SHARED "deps/glad.c" "deps/glad/glad.h")

# add_executable(Test1 src/test.cpp)

file(GLOB_RECURSE source_files ${PROJECT_SOURCE_DIR}/src/*)
add_executable(${APP_TARGET} ${source_files})

target_link_libraries(
    ${APP_TARGET}
    glfw
    GLAD
    # ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    # ${EXTRA_LIBS}
)
