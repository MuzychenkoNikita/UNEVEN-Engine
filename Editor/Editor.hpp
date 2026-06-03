#include <iostream>
#include <imgui/imgui.h>

#include "Core/Core.hpp"

class Editor : public UNEVEN::Project {
public:
    void OnStart(UNEVEN::Context ctx) override;
    void OnUpdate(UNEVEN::Context ctx, float dt) override;
    void OnStop(UNEVEN::Context ctx) override;
    
    
    
public:
    unsigned int SCR_WIDTH = 1920;
    unsigned int SCR_HEIGHT = 1080;

    //ImGuiIO* io = nullptr;
    
private:
    // Main functions
    /*
    void InitiateInterface(UNEVEN::Context ctx);
    void RenderInterface(UNEVEN::Context ctx);
    void CleanInterface(UNEVEN::Context ctx);
    void DestroyInterface(UNEVEN::Context ctx);

    // Interface Windows
    void ProjectWindow();
    void ViewportWindow();
    void HierarchyWindow();
    void InspectorWindow();
    void ConsoleWindow();
    void MenuBar();

    // Helper Functions
    void ApplyDefaultTheme();
     */
};
