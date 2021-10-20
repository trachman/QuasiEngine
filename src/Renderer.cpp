#include "Renderer.h"
#include <iostream>


/* ERROR HANDLING IMPLEMENTATIONS */
void GLClearError()
{
	while(glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OPENGL ERROR] (" << error << ") "
			<< function << ' ' << file << ':' << line << std::endl;
		return false;
	}
	return true;
}
/* END OF ERROR HANDLING */

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	shader.Bind();
	// shader.SetUniform4f("u_Colour", r, 0.3f, 0.8f, 1.0f);
	va.Bind();
	ib.Bind();
	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}
