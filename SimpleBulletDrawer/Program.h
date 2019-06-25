#ifndef _PROGRAM_H_
#define _PROGRAM_H_

#include <initializer_list>

namespace Shading
{
    class Shader;

    class Program
    {
    public:
        Program(std::initializer_list<Shader> shaders);
        Program(const Program& otherProgram) = delete;
        Program(Program&& otherProgram);

        Program& operator=(const Program& otherProgram) = delete;
        Program& operator=(Program&& otherProgram);
        ~Program();
    public:
        unsigned int Id() const noexcept;
    private:
        unsigned int mProgramId;
    };
}

#endif