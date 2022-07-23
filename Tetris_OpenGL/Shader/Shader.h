#pragma once

#include <string>
#include <fstream>
#include <glad/glad.h>

/**
*	This class is used to build the shader.
*/
class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();

	/**
	*	This function is used to attach the shader program on main.
	*/
	void AttachShader(const char* FileName, unsigned int ShaderType);
	void LinkShader();
	void UseProgram();

private:

	//	This function is used to convert file location into string properly.
	std::string CatchFile(const std::string FileName);

	unsigned int ProgramId;
};

