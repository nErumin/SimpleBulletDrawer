#include "InputManager.h"

using namespace Management;


std::unique_ptr<InputManager> InputManager::sInstancePtr = nullptr;

InputManager& InputManager::Instance()
{
    if (!sInstancePtr)
    {
        sInstancePtr = std::unique_ptr<InputManager>(new InputManager);
    }

    return *sInstancePtr;
}

InputManager::InputManager() = default;

bool InputManager::IsKeyRepeated(int key)
{
    if (mKeyRepeatingMap.find(key) == mKeyRepeatingMap.end())
    {
        return false;
    }

    return mKeyRepeatingMap[key];
}

void InputManager::SetKeyRepeatState(int key, bool isRepeated)
{
    if (mKeyRepeatingMap.find(key) == mKeyRepeatingMap.end())
    {
        mKeyRepeatingMap.emplace(key, isRepeated);
    }
    else
    {
        mKeyRepeatingMap[key] = isRepeated;
    }
}