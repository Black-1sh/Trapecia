#define GLEW_DLL
#define GLFW_DLL

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"

void drawTriangle() {
    glBegin(GL_TRIANGLES);

    // Цвет фигуры (r, g, b) = (0.3, 1.0, 1.0)
    glColor3f(0.3, 1.0, 1.0);

    // Вершины треугольника
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);

    glEnd();
}

int main() {
    if (!glfwInit()) {
        printf("Ошибка инициализации GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(500, 500, "triangle", NULL, NULL);
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
        // Цвет фона (r, g, b) = (1.0, 1.0, 1.0)
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        drawTriangle();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
