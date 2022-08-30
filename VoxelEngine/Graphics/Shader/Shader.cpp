#include "Shader.h"

void checkCompileErrors(unsigned int object, std::string type);



void Shader::CreateProgram(const char* Vertex_Source, const char* Fragment_Source)
{
    unsigned int sVertex, sFragment;
    // vertex Shader
    sVertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(sVertex, 1, &Vertex_Source, nullptr);
    glCompileShader(sVertex);
    checkCompileErrors(sVertex, "VERTEX");
    // fragment Shader
    sFragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(sFragment, 1, &Fragment_Source, nullptr);
    glCompileShader(sFragment);
    checkCompileErrors(sFragment, "FRAGMENT");

    // shader program
    this->pID = glCreateProgram();
    glAttachShader(this->pID, sVertex);
    glAttachShader(this->pID, sFragment);
    glLinkProgram(this->pID);
    checkCompileErrors(this->pID, "PROGRAM");
    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(sVertex);
    glDeleteShader(sFragment);
}
void Shader::ClearProgram()
{
    glDeleteProgram(this->pID);
}

void Shader::Bind()
{ glUseProgram(this->pID); }

void Shader::SetInt(const char* Name, int value) {  }
void Shader::SetFloat(const char* Name, float value) {  }
void Shader::SetVec2(const char* Name, float x, float y) {  }
void Shader::SetVec3(const char* Name, float x, float y, float z) {  }
void Shader::SetVec4(const char* Name, float x, float y, float z, float w) {  }
void Shader::SetMat4(const char* Name, glm::mat4 matrix) { glUniformMatrix4fv(glGetUniformLocation(this->pID, Name), 1, false, glm::value_ptr(matrix)); }


#include <iostream>
#include <string>
void checkCompileErrors(unsigned int object, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(object, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(object, 1024, NULL, infoLog);
            std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
                << infoLog << "\n -- --------------------------------------------------- -- "
                << std::endl;
        }
    }
    else
    {
        glGetProgramiv(object, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(object, 1024, NULL, infoLog);
            std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
                << infoLog << "\n -- --------------------------------------------------- -- "
                << std::endl;
        }
    }
}