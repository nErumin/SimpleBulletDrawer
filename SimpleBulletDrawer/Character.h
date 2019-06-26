#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <memory>
#include "Actor.h"

namespace Object
{
    class Character : public Actor
    {
    public:
        static Character& Instance();
    private:
        static std::unique_ptr<Character> sInstancePtr;
    public:
        std::shared_ptr<Shape::IShape> Shape() const override;
        void Initialize() override;
        void Update() override;
    private:
        Character();
    };
}

#endif // !_CHARACTER_H_
