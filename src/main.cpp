#include "config.h"



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main() {
    glfwInit();

    // tell glfw to use core profile of opengl
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* window = glfwCreateWindow(800, 600, "MY WINDOW", NULL, NULL);


    if(window == NULL) {
        std::cout << "GLFW window failed to create" << std::endl;
        glfwTerminate();
        return -1;
    }
    // introducre the window into the current context
    glfwMakeContextCurrent(window);

    // lopad glad so it configures opengl
    gladLoadGL();
    // specify the viewport of OpenGL in the window
    // in this case the viewport goes from (0,0) to (800,600)
    glViewport(0, 0, 800, 600);


    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // front buffer - memory from which image is displayed
    // back buffer - memory to which info is written to output in the future while pixels are rendering from the front buffer
    // then, they swap the roles

    // specify the colot in the background
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    // clean the back buffer and assign the new color to it
    glClear(GL_COLOR_BUFFER_BIT);
    // swap the back buffer with the front buffer
    glfwSwapBuffers(window);


    std::cout << "OpenGL vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "OpenGL renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;


    while(!glfwWindowShouldClose(window)) {
        // take care of all GLFW events

        // input event: press SPACE to close window
        processInput(window);


        //glClearColor(0.07f, 0.13f, 0.5f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate(); // clean all GLFD resources
    return 0;
}

//----------------------------------------------------------------------------------------------

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
}

//----------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, 1);
    }
}