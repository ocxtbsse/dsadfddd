#pragma  once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>



class Window{
    public:
    GLFWwindow* window;

    int createWindow(int windowWidth,int windowHeight, char* sigmaSwagTitle322){
        if (!glfwInit()) {
            std::cerr << "GLFW init failed!" << std::endl;
            return 1;
        }
        
            // 2. Создание окна
        window = glfwCreateWindow(windowWidth, windowHeight, sigmaSwagTitle322, NULL, NULL);
        if (!window) {
            glfwTerminate();
            return 1;
        }
        glfwMakeContextCurrent(window);
                // 3. Инициализация GLEW (Строго после контекста!) или атата
        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            std::cerr << "GLEW init failed!" << std::endl;
            return 1;
        }

        return 0;
    }
};

