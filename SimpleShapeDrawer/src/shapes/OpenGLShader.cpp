#include "OpenGLShader.h"



OpenGLShader::OpenGLShader(const GLchar* vertexPath, const GLchar* fragmentPath) {
        // 1. �������� �������� ��� ������� �� filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        // �������������, ��� ifstream ������� ����� ���������� ����������
        vShaderFile.exceptions(std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::badbit);
        try
        {
                // ��������� �����
                vShaderFile.open(vertexPath);
                fShaderFile.open(fragmentPath);
                std::stringstream vShaderStream, fShaderStream;
                // ��������� ������ � ������
                vShaderStream << vShaderFile.rdbuf();
                fShaderStream << fShaderFile.rdbuf();
                // ��������� �����
                vShaderFile.close();
                fShaderFile.close();
                // ��������������� ������ � ������ GLchar
                vertexCode = vShaderStream.str();
                fragmentCode = fShaderStream.str();
        } catch (std::ifstream::failure e)
        {
                std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
        const GLchar* vShaderCode = vertexCode.c_str();
        const GLchar* fShaderCode = fragmentCode.c_str();

        // 2. ������ ��������
        GLuint vertex, fragment;
        GLint success;
        GLchar infoLog[512];

        // ��������� ������
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        // ���� ���� ������ - ������� ��
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success)
        {
                glGetShaderInfoLog(vertex, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        };

        // ���������� ��� ������������ �������
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        // ���� ���� ������ - ������� ��
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success)
        {
                glGetShaderInfoLog(fragment, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        };

        // ��������� ���������
        this->Program = glCreateProgram();
        glAttachShader(this->Program, vertex);
        glAttachShader(this->Program, fragment);
        glLinkProgram(this->Program);
        //���� ���� ������ - ������� ��
        glGetProgramiv(this->Program, GL_LINK_STATUS, &success);
        if (!success)
        {
                glGetProgramInfoLog(this->Program, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }

        // ������� �������, ��������� ��� ��� � ��������� � ��� ������ �� �����.
        glDeleteShader(vertex);
        glDeleteShader(fragment);

}


void OpenGLShader::SetBool(const std::string& name, GLboolean value) {
        glUniform1i(glGetUniformLocation(this->Program, name.c_str()), (int)value);
}


void OpenGLShader::SetInt(const std::string& name, GLint value) {
        glUniform1i(glGetUniformLocation(this->Program, name.c_str()), value);
}


void OpenGLShader::SetInt2(const std::string& name, GLint* valuePtr) {
        SetInt2(name, valuePtr[0], valuePtr[1]);
}


void OpenGLShader::SetInt2(const std::string& name, GLint value1, GLint value2) {
        glUniform2i(glGetUniformLocation(this->Program, name.c_str()), value1, value2);
}


void OpenGLShader::SetInt3(const std::string& name, GLint* valuePtr) {
        SetInt3(name, valuePtr[0], valuePtr[1], valuePtr[2]);
}


void OpenGLShader::SetInt3(const std::string& name, GLint value1, GLint value2, GLint value3) {
        glUniform3i(glGetUniformLocation(this->Program, name.c_str()), value1, value2, value3);
}


void OpenGLShader::SetFloat(const std::string& name, GLfloat value) {
        glUniform1f(glGetUniformLocation(this->Program, name.c_str()), value);
}


void OpenGLShader::SetFloat2(const std::string& name, GLfloat* valuePtr) {
        this->SetFloat2(name, valuePtr[0], valuePtr[1]);
}


void OpenGLShader::SetFloat2(const std::string& name, GLfloat value1, GLfloat value2) {
        glUniform2f(glGetUniformLocation(this->Program, name.c_str()), value1, value2);
}


void OpenGLShader::SetFloat3(const std::string& name, GLfloat* valuePtr) {
        SetFloat3(name, valuePtr[0], valuePtr[1], valuePtr[2]);
}


void OpenGLShader::SetFloat3(const std::string& name, GLfloat value1, GLfloat value2, GLfloat value3) {
        glUniform3f(glGetUniformLocation(this->Program, name.c_str()), value1, value2, value3);
}


void OpenGLShader::Use() { 
        glUseProgram(this->Program); 
}