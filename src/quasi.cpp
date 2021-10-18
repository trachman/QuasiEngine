#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
	GLFWwindow* window;

	// initialize the library
	if (!glfwInit())
		return -1;

	// create a windowed mode window and context
	window = glfwCreateWindow(640,480,"Hello World",NULL,NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// make the current windows context current
	glfwMakeContextCurrent(window);

	// loop until the user closes the window
	while(!glfwWindowShouldClose(window))
	{
		// render here
		glClear(GL_COLOR_BUFFER_BIT);

		// swap front and back buffers
		glfwSwapBuffers(window);

		// poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
