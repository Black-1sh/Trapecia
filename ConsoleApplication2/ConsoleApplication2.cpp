#define GLWF
#define GLEW

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void drawTrapezoid() {
    glBegin(GL_POLYGON);

    glColor3f(0.5, 0.5, 1.0);

    glVertex2f(0.0, 0.0);
    glVertex2f(0.8, 0.0);
    glVertex2f(0.6, 0.6);
    glVertex2f(0.2, 0.6);

    glEnd();
}

int main() {
    if (!glfwInit()) {
        printf("Ошибка инициализации GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(500, 500, "Трапеция", NULL, NULL);
    if (!window) {
        printf("Ошибка создания окна\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        printf("Ошибка инициализации GLEW\n");
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {

        glClearColor(1.0, 1.0, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        drawTrapezoid();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}