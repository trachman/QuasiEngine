#pragma once

#include <GL/glew.h>

/* ERROR HANDLING CODE */
// WHEN YOU WANT TO DEBUG A FUNCTION JUST WRAP
// IT WITH GLCall(__func__)
#define ASSERT(x) if (!(x)) exit(1);
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
/* END OF ERROR HANDLING DEFINITIONS */
