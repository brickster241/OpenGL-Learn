/* Always include GLAD before GLFW */

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

void frame_buffersize_callback(GLFWwindow* window, int width, int height);

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Set up the Version and core profile */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 900, "Welcome to OPENGL Window", NULL, NULL);
    if (!window)
    {
        std::cout << "Window Creation Failed !!!\n";
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    /* Set a callback to change the viewport whenever video is resized */
    glfwSetFramebufferSizeCallback(window, frame_buffersize_callback);

    /* Load OPENGL Function Pointers */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        
        std::cout << "Failed to load OPENGL Function pointers !!!\n";
        glfwTerminate();
        return -1;
    }

    float r = 0.0f, b = 0.0f, g = 0.0f;
    float dr = 0.0001f, db = 0.0001f, dg = 0.0001f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Close the window on Escape Key Press */
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        /* Set Clear Color and change it dynamically */
        r = 0.4f + remainderf(r + dr, 0.6f);
        g = 0.25f + remainderf(g + dg, 0.75f);
        b = 0.5f + remainderf(b + db, 0.5f);
        glClearColor(r, g, b, 1.0f);


        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void frame_buffersize_callback(GLFWwindow* window, int width, int height) {

    /* Setting Viewport width and height on resize */
    std::cout << "New Width, Height : (" << width << "," << height << ")" << "\n";
    glViewport(0, 0, width, height);
}