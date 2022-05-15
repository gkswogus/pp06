#include <GLFW/glfw3.h>

#include <stdlib.h>

#include <stdio.h>

#include<windows.h>

#define GLUT_KEY_UP 101



#pragma comment(lib,"opengL32")



static void error_callback(int error, const char* description)

{

    fputs(description, stderr);

}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)

{

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)

        glfwSetWindowShouldClose(window, GL_TRUE);

}

void main()

{

    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())

        exit(EXIT_FAILURE);

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);

    if (!window)

    {

        glfwTerminate();

        exit(EXIT_FAILURE);

    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);

    float x1, x2, x3;
    
    x1 = 0.8f;
    x2 = 0.7f;
    x3 = 0.9f;


 


    while (!glfwWindowShouldClose(window))

    {

        float ratio;

        int width, height;

        glfwGetFramebufferSize(window, &width, &height);

        ratio = width / (float)height;


       glClearColor(1, 1, 1, 1); 

        glClear(GL_COLOR_BUFFER_BIT);     


        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);

       

        glVertex2f(x1, 0.0f);
       

        glVertex2f(x2, -0.1f);
        

        glVertex2f(x3, -0.1f);
      
        x1 -= 0.0007f;
        x2 -= 0.0007f;
        x3 -= 0.0007f;
         
     
        glEnd();

        if (x1 < -1.0f)
            x1 = 0.8f;
        else
            x1 = x1 - 0.00007;

        if (x2 < -1.1f)
            x2 = 0.7f;
        else
            x2 = x2 - 0.00007;

        if (x3 < -0.9f)
            x3 = 0.9f;
        else
            x3 = x3 - 0.00007;



        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            glBegin(GL_TRIANGLES);

            glColor3f(0.0f, 0.5f, 0.0f);

            glVertex2f(-0.5f, 0.3f);

            glVertex2f(-0.5f, 0.1f);

            glVertex2f(-0.7f, 0.1f);

            glEnd();

            glBegin(GL_TRIANGLES);

            glColor3f(0.0f, 0.5f, 0.0f);

            glVertex2f(-0.5f, 0.3f);

            glVertex2f(-0.7f, 0.3f);    

            glVertex2f(-0.7f, 0.1f);

            glEnd();

        }
        else
        {
            glBegin(GL_TRIANGLES);

            glColor3f(0.0f, 0.51f, 0.0f);

            glVertex2f(-0.5f, 0.0f);

            glVertex2f(-0.5f, -0.2f);

            glVertex2f(-0.7f, -0.2f);

            glEnd();

            glBegin(GL_TRIANGLES);

            glColor3f(0.0f, 0.51f, 0.0f);

            glVertex2f(-0.5f, 0.0f);

            glVertex2f(-0.7f, 0.0f);

            glVertex2f(-0.7f, -0.2f);

            glEnd();
        }



        glfwSwapBuffers(window);

        glfwPollEvents();

    }

    glfwDestroyWindow(window);

    glfwTerminate();

    exit(EXIT_SUCCESS);

}