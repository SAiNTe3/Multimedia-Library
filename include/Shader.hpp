#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"
typedef unsigned int uint;
typedef unsigned int GLuint;
class Shader {
	uint m_Program = 0;
public:
    explicit Shader(const char* vertexPath, const char* fragmentPath);
    explicit Shader(const std::string& vertexCode, const std::string& fragmentCode);
    void load();
    void unload();
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setMat4(const std::string& name, glm::mat4& matrix) const;
    void setVec4(const std::string& name, glm::vec4& vector) const;
    void setVec2(const std::string& name, glm::vec2& vector) const;
};