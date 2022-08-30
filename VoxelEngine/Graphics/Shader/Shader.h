#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Shader
{
private:
	GLuint pID;

public:
	void CreateProgram(const char* Vertex_Source, const char* Fragment_Source);
	void ClearProgram();

	void Bind();

	void SetInt(const char* Name, int value);
	void SetFloat(const char* Name, float value);
	void SetVec2(const char* Name, float x, float y);
	void SetVec3(const char* Name, float x, float y, float z);
	void SetVec4(const char* Name, float x, float y, float z, float w);
	void SetMat4(const char* Name, glm::mat4 matrix);
};



#include <iostream>
#include <sstream>
#include <fstream>
namespace SHADER
{
    static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile)
    {
        // 1. retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;
        try
        {
            // open files
            std::ifstream vertexShaderFile(vShaderFile);
            std::ifstream fragmentShaderFile(fShaderFile);
            std::stringstream vShaderStream, fShaderStream;
            // read file's buffer contents into streams
            vShaderStream << vertexShaderFile.rdbuf();
            fShaderStream << fragmentShaderFile.rdbuf();
            // close file handlers
            vertexShaderFile.close();
            fragmentShaderFile.close();
            // convert stream into string
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::exception e)
        {
            std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
        }
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
        // 2. now create shader object from source code
        Shader shader;
        shader.CreateProgram(vShaderCode, fShaderCode);
        return shader;
    }
}