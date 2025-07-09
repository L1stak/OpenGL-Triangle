#pragma once
class Shaders
{
protected:
	unsigned int ID;
public:
	Shaders(const char* vertexPath, const char* fragmentPath);
	~Shaders();
	void use();

};

