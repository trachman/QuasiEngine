#include <iostream>

// glew is used to extract drivers for opengl
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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

	// code added from stack overflow directly addressing the cherno's video 
	// https://stackoverflow.com/questions/62990972/why-is-opengl-giving-me-the-error-error-01-version-330-is-not-support
  	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	std::cout << "This is an Apple Computer." << std::endl;
  	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	// stack overflow code chunk complete
	
	// create a windowed mode window and context
	window = glfwCreateWindow(640,480,"OPENGL TUTORIAL",NULL,NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// make the current windows context current
	glfwMakeContextCurrent(window);

	// this line of code must be called after the context
	if (glewInit() != GLEW_OK)
		std::cout << "Error occurred with glewInit()" << std::endl;

	// print opengl version
	std::cout << glGetString(GL_VERSION) << std::endl;

	// ModernOpenGl Implemenation
	float positions[] = {
		-0.5f, -0.5f,
		0.0f, 0.5f,
		0.5f, -0.5f
	};

	// more stack overflow code
	unsigned int VBO, VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), positions, GL_STATIC_DRAW);
	// stack overflow code chunk complete 
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, 0);

	// write the shaders
	std::string vertexShader = 
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"}\n";

	std::string fragmentShader = 
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 colour;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	colour = vec4(1.0, 0.0, 0.0, 1.0);\n"
		"}\n";

	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader); // bind the new shaders

	// loop until the user closes the window
	while(!glfwWindowShouldClose(window))
	{
		// render here
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		// swap front and back buffers
		glfwSwapBuffers(window);

		// poll for and process events
		glfwPollEvents();
	}

	// delete the stack overflow shaders
	glDeleteVertexArrays(1, &VAO);
  	glDeleteBuffers(1, &VBO);
  	glDeleteProgram(shader);
	// stack overflow code chunk complete

	glfwTerminate();
	return 0;
}
