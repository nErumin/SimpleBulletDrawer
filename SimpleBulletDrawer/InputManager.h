#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_

#include <memory>
#include <unordered_map>

namespace Management
{
    class InputManager
    {
    public:
        static InputManager& Instance();
    private:
        static std::unique_ptr<InputManager> sInstancePtr;
    public:
        bool IsKeyRepeated(int key);
        void SetKeyRepeatState(int key, bool isRepeated);
    private:
        InputManager();
    private:
        std::unordered_map<int, bool> mKeyRepeatingMap;
    };
}

#endif // !_INPUT_MANAGER_H_
