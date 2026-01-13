#include <glad/glad.h>
#include <iostream>
#include <string>
#include <vector>
#include "Shader.h"
#include "Window.h"
#include "Mesh.h"

int main()
{
    Window win(800, 600, "fraCtal");

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    std::cout << "GLAD initialized successfully" << std::endl;

    Shader ourShader("shaders/vertex.glsl", "shaders/fragment.glsl");

    std::cout << "Shaders loaded and compiled" << std::endl;

    std::vector<float> vertices = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    Mesh triangle(vertices);

	//	Run window (main loop)
    while (!win.shouldClose()) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		//	Draw triangle
		ourShader.use();
		triangle.draw();
		
        win.swapBuffers();
        win.pollEvents();
    }

    return 0;
}