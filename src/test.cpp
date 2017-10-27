// #include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <stdlib.h>
#include <stdio.h>
// using namespace std;
//
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    std::cout << "resize:" << width <<"," << height << std::endl;
    glViewport(0, 0, width, height);
}

//键盘
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
    glfwInit();

    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    std::cout << "ok" << std::endl;
    glfwMakeContextCurrent(window);
    //初始化glad, 调用opengl函数之前调用
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        std::cout << "glad init error" << std::endl;
        exit(EXIT_SUCCESS);
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while(!glfwWindowShouldClose(window)){
        //处理输入
        processInput(window);
        int width, height;
        //读取buffer的尺寸
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        //清屏
        // glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //交换缓冲
        glfwSwapBuffers(window);
        //窗口事件: 关闭窗口等
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);

    return 0;
}
