#pragma once 
#include <GLFW/glfw3.h>



class Time {
public:
    static float deltaTime;
    static float lastFrame;

    static void update() {
        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
    }
};

float Time::deltaTime = 0.0f;
float Time::lastFrame = 0.0f;
