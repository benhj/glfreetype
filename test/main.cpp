// Hacky test

#include "glfreetype/TextRenderer.hpp"
#include <GLFW/glfw3.h>

int main(int argc, char **argv)
{

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    int windowWidth = 300;
    int windowHeight = 40;
    window = glfwCreateWindow(windowWidth, windowHeight, "glfreetype test", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // NEHE's font system
    glfreetype::font_data our_font;
    our_font.init("/Library/Fonts/Arial.ttf", 25 /* size */);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glClearColor(255.0, 255.0, 255.0, 0.0);

        glPushMatrix();
        glLoadIdentity();

        // Blue text
        glColor3ub(0,0,0xff);

        glfreetype::print(our_font, 20 /* xpos */, 20 /* ypos */, 
                          "The quick brown fox blah blah blah");

        glPopMatrix();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    our_font.clean();
    glfwTerminate();
    return 0;
}
