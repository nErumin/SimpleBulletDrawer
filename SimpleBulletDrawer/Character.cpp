#include "Character.h"
#include "RegularTriangle.h"
#include "InputManager.h"
#include "GLFW/glfw3.h"

using namespace Object;

std::unique_ptr<Character> Character::sInstancePtr = nullptr;

Character& Character::Instance()
{
    if (!sInstancePtr)
    {
        sInstancePtr = std::unique_ptr<Character>{ new Character };
    }

    return *sInstancePtr;
}

Character::Character() = default;

std::shared_ptr<Shape::IShape> Character::Shape() const
{
    return std::make_shared<Shape::RegularTriangle>(1.0f, glm::vec3{ 1.0f, 1.0f, 0.0f });
}

void Character::Initialize()
{
    Position().y -= 7.5f;
    Position().z += 1.0f;
}

void Character::Update()
{
    auto& inputManagerRef = Management::InputManager::Instance();

    if (inputManagerRef.IsKeyRepeated(GLFW_KEY_UP))
    {
        Position().y += 0.02f;
    }

    if (inputManagerRef.IsKeyRepeated(GLFW_KEY_DOWN))
    {
        Position().y -= 0.02f;
    }

    if (inputManagerRef.IsKeyRepeated(GLFW_KEY_LEFT))
    {
        Position().x -= 0.02f;
    }

    if (inputManagerRef.IsKeyRepeated(GLFW_KEY_RIGHT))
    {
        Position().x += 0.02f;
    }
}
