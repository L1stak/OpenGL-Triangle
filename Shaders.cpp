#include "Shaders.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <glew.h>
inline std::string readFile(const char* Path) {

	std::stringstream ss;
	std::fstream stream(Path);

	if (!stream.is_open()) {
		throw std::string("Failed to load file " + std::string(Path));
	}
	ss << stream.rdbuf();
	stream.close();

	return ss.str();

}
inline void checkShaderCompile(GLuint shader) {
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar infoLog[512];
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

Shaders::Shaders(const char* vertexPath, const  char* fragmentPath) {
	std::string vertex = readFile(vertexPath);
	std::string fragment = readFile(fragmentPath);

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader =  glCreateShader(GL_FRAGMENT_SHADER);
	
	const char* vraw = vertex.c_str();
	const char* fraw = fragment.c_str();


	// compile shaders
	glShaderSource(vertexShader, 1, &vraw, nullptr);
	glShaderSource(fragmentShader, 1, &fraw, nullptr);

	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	checkShaderCompile(vertexShader);
	checkShaderCompile(fragmentShader);
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);

	glLinkProgram(ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shaders::~Shaders() {
	glDeleteShader(ID);
	
}

void Shaders::use() {
	glUseProgram(ID);


}