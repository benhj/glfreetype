# glfreetype
Another OpenGL FreeType library

I needed the ability to display text in OpenGL. I discovered FreeType and the following NeHe tutorial:

http://nehe.gamedev.net/tutorial/freetype_fonts_in_opengl/24001/

The repository here is basically a simple amalgamation of those ideas.

Assuming a cmake build system, clone this repository into your source tree and add the following lines to your CMakeLists.txt file:

```
find_package(OpenGL REQUIRED)
find_package(Freetype REQUIRED)
file(GLOB_RECURSE glfreetype glfreetype/src/*.cpp glfreetype/include/glfreetype/*.hpp)
include_directories(glfreetype/include)
add_library(glfreetype_lib ${glfreetype})
target_compile_options(glfreetype_lib PUBLIC ${COMP_FLAGS})
```

Note, you will also need to link with glfreetype_lib during the linking stage of whatever project you're building. This can be done by editing the following line in your CMakeLists.txt file:

```
target_link_libraries(executableName some_lib some_other_lib etc_lib glfreetype_lib ${OPENGL_LIBRARIES} glfw ${FREETYPE_LIBRARIES})
```

## Please check out the test binary (build from the source root with):

```
mkdir build
cd build
cmake ..
make
```
