cmake_minimum_required (VERSION 3.1)
project (glfreetype)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(Freetype REQUIRED)

# put all source code in one place for convenience
# note, when you do this in your own project, the src and include paths
# would likely be glfreetype/src/*.cpp and 
# glfreetype/include/glfreetpye/*.hpp respectively.
file(GLOB_RECURSE glfreetype src/*.cpp include/glfreetype/*.hpp)

# ensure headers in the src folder are compiler-found
# Note, in your own project the following include path 
# would likely be glfreetype/include
include_directories(include)
include_directories(/usr/local/include/)
include_directories( ${OPENGL_INCLUDE_DIRS} )
include_directories( ${FREETYPE_INCLUDE_DIRS} )

# break above sub-folders into individual libraries
add_library(glfreetype_lib ${glfreetype})
add_executable(wintest test/main.cpp)
target_link_libraries(wintest glfreetype_lib ${OPENGL_LIBRARIES} glfw ${FREETYPE_LIBRARIES})

# compile options. Lots of redundancy here. Can prob clean up.
set(COMP_FLAGS -std=c++14 -O3 -ffast-math -funroll-loops -Wno-ctor-dtor-privacy -fno-pic -Wno-deprecated)
target_compile_options(glfreetype_lib PUBLIC ${COMP_FLAGS})
target_compile_options(wintest PUBLIC ${COMP_FLAGS})
