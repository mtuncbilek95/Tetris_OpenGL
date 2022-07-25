#pragma once

#define WIDTH 800
#define HEIGHT 800

unsigned int programId, VBO, VAO;

float vertices[] = {
	-0.5f,  0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,

	-0.5f,  0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.5f,  0.5f, 0.0f,
};

//float indices[] = {
//	0,1,3,
//	1,2,3
//};