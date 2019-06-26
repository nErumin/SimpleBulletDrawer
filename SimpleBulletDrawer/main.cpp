#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <cstdlib>

#include "ActorDrawer.h"
#include "Screen.h"
#include "OrthographicCamera.h"
#include "InputManager.h"
#include "Time.h"
#include "DirectionStageFactory.h"
#include "NWayStageFactory.h"
#include "SplitStageFactory.h"
#include "CircularStageFactory.h"

namespace
{
    void HandleError(int errorCode, const char* errorMessage)
    {
        std::cerr << "Library Error: Code = " << errorCode 
                  << ", Message = " << errorMessage << std::endl;
    }

    void HandleKeyInput(GLFWwindow* windowHandler, int key, int scanCode, int action, int modifiers)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(windowHandler, GLFW_TRUE);
        }
        
        bool isKeepPressed = (action == GLFW_REPEAT) || (action == GLFW_PRESS);
        Management::InputManager::Instance().SetKeyRepeatState(key, isKeepPressed);
    }

    void InitializeGlfwLibrary()
    {
        glfwSetErrorCallback(HandleError);

        if (!glfwInit())
        {
            std::cerr << "GLFW initialization failed!" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void InitializeScreen()
    {
        using namespace Management;
        
        Screen::Instance().Width() = 600;
        Screen::Instance().Height() = 800;
    }

    GLFWwindow* CreateGlfwWindow()
    {
        using namespace Management;

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

        // For MacOS
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        glfwWindowHint(GLFW_SAMPLES, 4);

        auto windowHandler = glfwCreateWindow(Screen::Instance().Width(), 
                                              Screen::Instance().Height(), 
                                              "SimpleBulletDrawer", 
                                              nullptr, 
                                              nullptr);

        return windowHandler;
    }

    void InitializeGlewLibrary()
    {
        glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK)
        {
            std::cerr << "GLEW initialization failed!" << std::endl;

            glfwTerminate();
            exit(EXIT_FAILURE);
        }
    }

    void SetupRenderingContext()
    {
        glfwSwapInterval(1);

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
    }

    void InitializeCamera()
    {
        auto& cameraRef = Object::OrthographicCamera::Instance();
        cameraRef.Position().z = 20.0f;

        cameraRef.PlaneX() = glm::vec2{ -10.0f, 10.0f };
        cameraRef.PlaneY() = glm::vec2{ -10.0f, 10.0f };
        cameraRef.PlaneZ() = glm::vec2{ -0.1f, 100.0f };
    }

    void CalculateTime()
    {
        using namespace Management;
        
        double currentTime = glfwGetTime();

        Time::DeltaTime() = currentTime - Time::LastRenderedTime();
        Time::LastRenderedTime() = currentTime;
    }
}

int main(int argc, char* argv[])
{
    InitializeScreen();
    InitializeGlfwLibrary();

    auto windowHandler = CreateGlfwWindow();

    if (!windowHandler)
    {
        std::cerr << "GLFW window creation failed!" << std::endl;
        
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(windowHandler);
    glfwSetKeyCallback(windowHandler, HandleKeyInput);
    
    InitializeGlewLibrary();
    SetupRenderingContext();
    
    InitializeCamera();

    using namespace Management;

    auto factoryPtr = std::make_unique<Factory::CircularStageFactory>();
    ActorDrawer::Instance().Initialize();

    Time::LastRenderedTime() = glfwGetTime();

    while (!glfwWindowShouldClose(windowHandler))
    {
        CalculateTime();

        factoryPtr->Produce();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ActorDrawer::Instance().Draw();

        glfwSwapBuffers(windowHandler);
        glfwPollEvents();
    }

    glfwTerminate();
    
    return 0;
}