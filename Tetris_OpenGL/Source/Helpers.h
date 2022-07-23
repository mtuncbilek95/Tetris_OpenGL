#pragma once

#define WIDTH 800
#define HEIGHT 800

using namespace std;

static unsigned int programId, VBO, VAO;

static float vertices[] = {
	-0.5f,  0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,

	-0.5f,  0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.5f,  0.5f, 0.0f,
};

static float indices[] = {
	0,1,3,
	1,2,3
};