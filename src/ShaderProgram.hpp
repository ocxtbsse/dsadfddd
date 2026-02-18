#pragma once 
#include <GL/glew.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include "Matrix.h"


class ShaderProgram{
    
    public:
    unsigned int ID;
    int compileShader(const char* vShader, const char* fShader){
        unsigned int v = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(v, 1, &vShader, 0);
        glCompileShader(v);

        unsigned int f = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(f, 1, &fShader, 0);
        glCompileShader(f);

        this->ID = glCreateProgram();
        glAttachShader(this->ID, v);
        glAttachShader(this->ID, f);
        glLinkProgram(this->ID);

        glDeleteShader(v);
        glDeleteShader(f);

        return 0;
    }
    void use() { 
        glUseProgram(ID);
    } 


    void setMat4(const char* name, glm::mat4 matrix) {// неведомо зачем
        glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, GL_FALSE, glm::value_ptr(matrix));
    }


    void setMat4x4(const char* name, Matrix mat){
        glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, GL_FALSE, mat.matrix4x4);
    }


    void setVec3(const std::string &name, const glm::vec3 &value) const {//скоро устранится
        glUniform3fv(glGetUniformLocation(this->ID, name.c_str()), 1, &value[0]);
    }

};
