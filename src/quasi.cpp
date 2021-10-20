#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// glew is used to extract drivers for opengl
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

static std::string ParseShader(const std::string& filepath)
{
	std::ifstream stream(filepath);

	std::string line;
	std::stringstream ss;
	while (getline(stream, line))
	{
		ss << line << '\n';	
	}
	return ss.str();
}

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	// ERROR HANDLING
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

		// below is a c function which allows you to dynamically
		// allocate to the stack, rather than having to go to 
		// the heap
		char* message = (char*) alloca(length*sizeof(char));

		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile" 
				  << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
				  << " shader." << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	
	return id;
}
	
// takes in the source code of these two types of shaders
static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);	
	glValidateProgram(program);

	// since the shaders are apart of the program,
	// we can get rid of the intermediate shaders
	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

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
		std::cout << "Error occurred with glewInit()" << std::endl;

	// print opengl version
	std::cout << glGetString(GL_VERSION) << std::endl;

	// ModernOpenGl Implemenation
	// coordinates
	float positions[] = {
		-0.5f, -0.5f, // 0
		0.5f, -0.5f, // 1
		0.5f, 0.5f, // 2
		-0.5f, 0.5f // 3
	};

	// determine the coordinates of the positions
	// array with which to draw the triangles
	unsigned int indices[] = { 
		0, 1, 2, // triangle 1
		2, 3, 0 // triangle 2
	};

	// initialize the vertex array and vertex buffer 
	VertexArray va;
	VertexBuffer vb(positions, 4*2*sizeof(float));

	// new abstracted api to be implemented
	VertexBufferLayout layout;
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	// initializing the index buffer
	IndexBuffer ib(indices, 6);

	// parse and create the shaders
	std::string vertexShader = ParseShader("res/shaders/vertex.shader");
	std::string fragmentShader = ParseShader("res/shaders/fragment.shader");
	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader); // bind the new shaders

	int location = glGetUniformLocation(shader, "u_Colour");
	ASSERT(location != -1);
	glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f);

	// unbind buffers
	glBindVertexArray(0);
	glUseProgram(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
	float r = 0.0f;
	float increment = 0.01f;
	while(!glfwWindowShouldClose(window))
	{
		// render here
		glClear(GL_COLOR_BUFFER_BIT);

		// rebind buffers
		glUseProgram(shader);

		// REMEMBER: uniforms are per draw
		glUniform4f(location, r, 0.3f, 0.8f, 1.0f);

		// glBindVertexArray(vao);
		va.Bind();
		ib.Bind();

		// debugging example 
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	
		// colour changing 
		if (r > 1.0f) increment = -0.01f;
		else if (r < 0.0f) increment = 0.01f;
		r += increment;

		glfwSwapBuffers(window); // swap front and back buffers
		glfwPollEvents(); // poll for and process events
	}

  	glDeleteProgram(shader);

	glfwTerminate();
	return 0;
}
