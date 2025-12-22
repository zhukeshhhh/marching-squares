#include "config.h"

int main() {
    
    GLFWwindow* window;

    if(!glfwInit()) {
        std::cout << "GLFW couldn't start!" << std::endl;
        return -1;
    }

    window = glfwCreateWindow(800, 600, "NEW WINDOW", NULL, NULL);
    glfwMakeContextCurrent(window);


    // tell glad to fetch all OpenGL procedures from the system
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        return -1;
    }

    glClearColor(0.25f, 0.1f, 0.7f, 1.0f);


    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}