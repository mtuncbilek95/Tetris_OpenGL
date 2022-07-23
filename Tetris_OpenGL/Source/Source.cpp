#pragma region "Libraries"
// Regular Libraries
#include <stdio.h>

// OpenGL Window and Render Libraries
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Shader Libraries
#include "../Shader/Shader.h"

// Window Macros
#include "Helpers.h"

// Entity Libraries

#pragma endregion

#pragma region "Source Functions"
void FrameBufferSize(GLFWwindow* window, int Width, int Height)
{
	glViewport(0, 0, Width, Height);
}
void ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
void CreateBuffer()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
	glEnableVertexAttribArray(0);
}
#pragma endregion

int main(int argumentCount, char** argumentValue)
{
	//Check if GLFW has been initialized.
	if (!glfwInit())
	{
		printf("Initialization has failed!");
		return 1;
	}

	//Version selection OpenGL 4.6
	glfwInitHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwInitHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	//Core profile configuration
	glfwInitHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/*
	* The code below is needed if the code runs on Mac OSX.
	* glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	*/

	//Initilalize the window.
	GLFWwindow* MainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Tetris OpenGL", NULL, NULL);

	//Check if window has been initialized.
	if (!MainWindow)
	{
		printf("Window initialization has failed!");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(MainWindow);

	//Check if GLAD has been initialized.
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("GLAD initialization has failed!");
		return 1;
	}

	//Declaring the Rendering Viewport to GLFW.
	glfwSetFramebufferSizeCallback(MainWindow, FrameBufferSize);

	//Initialize Shader.
	ShaderProgram MainProgram;

	//Attach Vertex and Fragment Shader.
	MainProgram.AttachShader("./GLSL/VertexShader.glsl", GL_VERTEX_SHADER);
	MainProgram.AttachShader("./GLSL/FragmentShader.glsl", GL_FRAGMENT_SHADER);

	//Link Shader.
	MainProgram.LinkShader();

	//Create shader buffers.
	CreateBuffer();

	while (!glfwWindowShouldClose(MainWindow))
	{
		//Input function
		ProcessInput(MainWindow);

		//Use Program and bind Vertex Array Object.
		MainProgram.UseProgram();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		//Rendering functions
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		//Continuously draw images and check for all inputs.
		glfwSwapBuffers(MainWindow);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}


