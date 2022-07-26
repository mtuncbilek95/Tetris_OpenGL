#include "Shader.h"

ShaderProgram::ShaderProgram()
{
	ProgramId = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(ProgramId);
}

void ShaderProgram::AttachShader(const char* FileName, unsigned int ShaderType)
{
	unsigned int ShaderId = glCreateShader(ShaderType);

	std::string SourceCode = CatchFile(FileName);
	const char* CharSource = &SourceCode[0];

	glShaderSource(ShaderId, 1, &CharSource, NULL);

	int isCompiled;
	char log[128];

	glCompileShader(ShaderId);
	glGetShaderiv(ShaderId, GL_COMPILE_STATUS, &isCompiled);

	if (!isCompiled)
	{
		glGetShaderInfoLog(ShaderId, sizeof(log), 0, log);
		printf("Shader Type: %d. \n %s", ShaderType, log);
	}

	glAttachShader(ProgramId, ShaderId);
}

void ShaderProgram::LinkShader()
{
	int isLinked;
	char log[128];

	glLinkProgram(ProgramId);
	glGetShaderiv(ProgramId, GL_LINK_STATUS, &isLinked);

	if (!isLinked)
	{
		glGetShaderInfoLog(ProgramId, sizeof(log), 0, log);
		printf("Link Type: %d. \n %s", ProgramId, log);
	}
}

void ShaderProgram::UseProgram()
{
	glUseProgram(ProgramId);
}

int ShaderProgram::GetLocation()
{
	return glGetUniformLocation(ProgramId, "UniColor");
}

void ShaderProgram::Uniform(float Color)
{
	glUniform4f(GetLocation(), 0.0f, Color, 0.0f, 1.0f);
}

std::string ShaderProgram::CatchFile(const std::string FileName)
{
	std::ifstream File(FileName);
	std::string Data;

	if (File.is_open())
	{
		char ReadData;
		while ((ReadData = File.get()) != EOF)
		{
			Data += ReadData;
		}
		File.close();
	}

	return Data;
}
