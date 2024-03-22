// https://habr.com/ru/articles/313380/

#define GLFW_INCLUDE_NONE
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class OpenGLShader
{
        #pragma region Поля
        public:

        // Идентификатор программы
        GLuint Program;
        #pragma endregion


        #pragma region Методы
        public:

        /// <summary> Конструктор экземпляра </summary>
        /// <param name="vertexPath"> Расположение файла с вершинным шейдером </param>
        /// <param name="fragmentPath"> Расположение файла с фрагментным шейдером </param>
        OpenGLShader(const GLchar* vertexPath, const GLchar* fragmentPath);


        void SetBool(const std::string& name, GLboolean value);


        void SetInt(const std::string& name, GLint value);


        void SetInt2(const std::string& name, GLint* valuePtr);


        void SetInt2(const std::string& name, GLint value1, GLint value2);


        void SetInt3(const std::string& name, GLint* valuePtr);


        void SetInt3(const std::string& name, GLint value1, GLint value2, GLint value3);


        void SetFloat(const std::string& name, GLfloat value);


        void SetFloat2(const std::string& name, GLfloat* valuePtr);


        void SetFloat2(const std::string& name, GLfloat value1, GLfloat value2);


        void SetFloat3(const std::string& name, GLfloat* valuePtr); 
        

        void SetFloat3(const std::string& name, GLfloat value1, GLfloat value2, GLfloat value3);


        // Использование программы
        void Use();
        #pragma endregion
};

#endif