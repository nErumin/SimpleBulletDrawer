#ifndef _SHADER_H_
#define _SHADER_H_

#include <iosfwd>
#include <string>

namespace Shading
{
    class Shader
    {
    public:
        Shader(int shaderType, const std::string& shaderSource);
        Shader(int shaderType, std::istream& stream);
        Shader(const Shader& otherShader) = delete;
        Shader(Shader&& otherShader);
        Shader& operator=(const Shader& otherShader) = delete;
        Shader& operator=(Shader&& otherShader);
        ~Shader();
    public:
        unsigned int Id() const noexcept;
        void Compile() const;
    private:
        std::string mShaderSource;
        unsigned int mShaderId;
        int mShaderType;
    };
}

#endif // !_SHADER_H_
