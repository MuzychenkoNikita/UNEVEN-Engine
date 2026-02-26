#include <iostream>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>

#include "Core/Core.hpp"

void InitEditor();
void EditorLoop();
void DestroyEditor();

class Editor : public UNEVEN::Project {
public:
    void OnStart() override;
    void OnUpdate(float dt) override;
    void OnStop() override;
    
    
    
public:
    GLFWwindow* window = nullptr;
    unsigned int SCR_WIDTH = 1920;
    unsigned int SCR_HEIGHT = 1080;

    ImGuiIO* io = nullptr;
    
private:
    // Main functions
    void InitiateInterface();
    void RenderInterface();
    void CleanInterface();
    void DestroyInterface();

    // Interface Windows
    void ProjectWindow();
    void ViewportWindow();
    void HierarchyWindow();
    void InspectorWindow();
    void ConsoleWindow();
    void MenuBar();

    // Helper Functions
    void ApplyDefaultTheme();
};
