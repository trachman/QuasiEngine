#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// glew is used to extract drivers for opengl
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

int main()
{
	GLFWwindow* window;

	// initialize the library
	if (!glfwInit())
		return -1;

  	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // these lines specify the version of opengl ie. 4.1
  	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // this is necessary on mac
	
	// create a windowed mode window and context
	window = glfwCreateWindow(640,480,"OPENGL TUTORIAL",NULL,NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// make the current windows context current
	glfwMakeContextCurrent(window);
	
	// cap framerate to monitor refresh rate
	glfwSwapInterval(1); 

	// this line of code must be called after the context
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error occurred with glewInit()" << std::endl;
		return 1;
	}

	std::cout << glGetString(GL_VERSION) << std::endl; // print opengl version

	// ModernOpenGl Implemenation
	// coordinates
	float positions[] = {
		-0.5f, -0.5f, 0.0f, 0.0f, // 0
		0.5f, -0.5f, 1.0f, 0.0f,// 1
		0.5f, 0.5f, 1.0f, 1.0f, // 2
		-0.5f, 0.5f, 0.0f, 1.0f // 3
	};

	// determine the coordinates of the positions
	// array with which to draw the triangles
	unsigned int indices[] = { 
		0, 1, 2, // triangle 1
		2, 3, 0 // triangle 2
	};

	/* blending determines how we combine the color 
	 * we output from our fragment shader (known as 
	 * source) with what is already in our target
	 * buffer */
	// need to enable and disable blending
	glEnable(GL_BLEND); 
	// blend function
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// there is also a glBlendEquation() function 
	// specifies how we combine the source and destination function

	// initialize the vertex array, vertex buffer, and index buffer
	VertexArray va;
	VertexBuffer vb(positions, 4 * 4 * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);
	IndexBuffer ib(indices, 6);

	// parse and create the shaders/uniforms
	Shader s;
	s.AddShader(GL_VERTEX_SHADER, "res/shaders/vertex.shader");
	s.AddShader(GL_FRAGMENT_SHADER, "res/shaders/fragment.shader");
	s.CreateShader();
	s.Bind();
	// s.SetUniform4f("u_Colour", 0.2f, 0.3f, 0.8f, 1.0f);

	Texture texture("res/textures/bluedragon.png");
	texture.Bind();
	s.SetUniform1i("u_Texture",0);

	// unbind buffers to show that they are still working with opengl
	va.Unbind();
	vb.Unbind();
	ib.Unbind();
	s.Unbind();
	
	Renderer renderer;

	float r = 0.0f;
	float increment = 0.01f;
	while(!glfwWindowShouldClose(window))
	{
		renderer.Clear();

		// rebind buffers
		s.Bind();
		// s.SetUniform4f("u_Colour", r, 0.3f, 0.8f, 1.0f); // REMEMBER: uniforms are per draw
	
		renderer.Draw(va, ib, s);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	
		// colour changing 
		if (r > 1.0f) increment = -0.01f;
		else if (r < 0.0f) increment = 0.01f;
		r += increment;

		glfwSwapBuffers(window); // swap front and back buffers
		glfwPollEvents(); // poll for and process events
	}

	s.Unbind();
	glfwTerminate();

	return 0;
}
