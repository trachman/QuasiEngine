#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class Shader
{
private:
	std::vector<unsigned int> m_Shaders;
	unsigned int m_Renderer_ID;
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader();
	~Shader();

	// adds a shader to m_Shaders
	void AddShader(unsigned int type, const std::string& filepath);
	void CreateShader();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetShader() const { return m_Renderer_ID; }

	// set uniforms
	void SetUniform1i(const std::string& name, int value);
	void SetUniform4f(const std::string& name, float f1, float f2, float f3, float f4);

private:
	std::string ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	int GetUniformLocation(const std::string& name);
};
