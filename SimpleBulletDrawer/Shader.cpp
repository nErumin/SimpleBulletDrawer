#include "Shader.h"
#include "GLEW/glew.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace Shading;

Shader::Shader(int shaderType, const std::string& shaderSource)
    : mShaderSource{ shaderSource },
      mShaderId{ glCreateShader(shaderType) },
      mShaderType{ shaderType }
{
}

Shader::Shader(int shaderType, std::istream& stream)
    : mShaderId{ glCreateShader(shaderType) },
      mShaderType{ shaderType }
{
    std::string line;
    std::ostringstream sourceStream;

    while (std::getline(stream, line))
    {
        sourceStream << line << std::endl;
    }

    mShaderSource = sourceStream.str();
}

Shader::Shader(Shader&& otherShader)
    : mShaderSource{ std::move(otherShader.mShaderSource) },
      mShaderId{ otherShader.mShaderId },
      mShaderType{ otherShader.mShaderType }
{
}

Shader& Shader::operator=(Shader&& otherShader)
{
    mShaderSource = std::move(otherShader.mShaderSource);
    mShaderId = otherShader.mShaderId;
    mShaderType = otherShader.mShaderType;

    return *this;
}

unsigned int Shader::Id() const noexcept
{
    return mShaderId;
}

void Shader::Compile() const
{
    auto sourcePtr = mShaderSource.c_str();
    
    glShaderSource(mShaderId, 1, &sourcePtr, nullptr);
    glCompileShader(mShaderId);

    int compileSuccessful = 0;
    int errorLogMessageLength = 0;

    glGetShaderiv(mShaderId, GL_COMPILE_STATUS, &compileSuccessful);
    glGetShaderiv(mShaderId, GL_INFO_LOG_LENGTH, &errorLogMessageLength);

    if (!compileSuccessful)
    {
        std::vector<char> logMessage(errorLogMessageLength + 1);
        glGetShaderInfoLog(mShaderId, errorLogMessageLength, nullptr, logMessage.data());

        throw std::logic_error{ std::string{ logMessage.data() } };
    }
}

Shader::~Shader()
{
    glDeleteShader(mShaderId);
}