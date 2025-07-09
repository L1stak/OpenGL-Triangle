#include <glew.h>
#include <glfw3.h>
#include "Shaders.h"
#include <iostream>
#include <cmath>
int main() {

	GLenum err;
	if (!glfwInit()) {
		std::cerr << "error init GLFW" << std::endl;
		return -1;
	}
	// some settings
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(500, 500, "Cube", nullptr, nullptr);
	if (!window) {
		std::cerr << "error to create window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);


	
	if ((err = glewInit() != GLEW_OK)) {
		std::cerr << "Error init GLEW, " <<  glewGetErrorString(err)<<std::endl;
		return -1;
	}
	



	Shaders Shaders("./vertex.glsl","./fragment.glsl");
	// coords
	GLfloat vertices[9] = {
		        -0.5f,-0.5f, 0.0f,
				 0.5f,-0.5f, 0.0f,
				 0.0f,0.5f , 0.0f

		
	};

	// buffers
	unsigned int VAO, VBO;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float),(const void*)0);
	glEnableVertexAttribArray(0);
	


	Shaders.use();
	while (!glfwWindowShouldClose(window)) {
		glViewport(0, 0, 500, 500);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		

	

		

	
		
	
		//draw
		glDrawArrays(GL_TRIANGLES, 0, 3);




		
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;


	
}