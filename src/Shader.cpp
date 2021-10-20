#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Renderer.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// for now empty constructor/destructor
Shader::Shader():m_Renderer_ID(0) {}

Shader::~Shader() 
{
	glDeleteProgram(m_Renderer_ID);
}

// parse, compile, then add to our list of shaders
void Shader::AddShader(unsigned int type, const std::string& filepath)
{
	std::string source = ParseShader(filepath);
	unsigned int shader = CompileShader(type, source);
	m_Shaders.push_back(shader);
}

// returns a string with the shader source code
std::string Shader::ParseShader(const std::string& filepath)
{
	std::ifstream stream(filepath);
	std::string line;
	std::stringstream ss;
	while (getline(stream, line)) { ss << line << '\n'; }
	return ss.str();
}

// returns unsigned int corrolated with shader
unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
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

// have to call this before bind
void Shader::CreateShader()
{
	// this is the create shader class
	unsigned int program = glCreateProgram();
	for (int i=0; i < m_Shaders.size(); i++)
		glAttachShader(program, m_Shaders[i]);
	
	glLinkProgram(program);
	glValidateProgram(program);

	for (int i=0; i<m_Shaders.size(); i++)
		glDeleteShader(m_Shaders[i]);

	m_Shaders.clear();
	m_Renderer_ID = program;
}

void Shader::Bind() const
{
	glUseProgram(m_Renderer_ID);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}


void Shader::SetUniform4f(const std::string& name, float f1, float f2, float f3, float f4)
{
	int location = GetUniformLocation(name);
	glUniform4f(location, f1, f2, f3, f4);
}

// the helper method to find location
unsigned int Shader::GetUniformLocation(const std::string& name)
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];
	int location = glGetUniformLocation(m_Renderer_ID, name.c_str());
	if (location == -1)
		std::cout << "Warning uniform '" << name << "' doesn't exist!" << std::endl;
	m_UniformLocationCache[name] = location;
	return location;
}
