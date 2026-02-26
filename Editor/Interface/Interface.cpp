#include "Editor.hpp"
#include "ThirdParty/tinyfiledialogs/tinyfiledialogs.h"

#include <GLFW/glfw3.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

void Editor::InitiateInterface() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = &ImGui::GetIO(); (void)io;
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    #ifdef __EMSCRIPTEN__
        ImGui_ImplGlfw_InstallEmscriptenCanvasResizeCallback("#canvas");
    #endif
        ImGui_ImplOpenGL3_Init("#version 330");
    ApplyDefaultTheme();
}
void Editor::RenderInterface() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::DockSpaceOverViewport();
    
    MenuBar();
    // Window Calls
    ProjectWindow();
    ViewportWindow();
    HierarchyWindow();
    InspectorWindow();
    ConsoleWindow();
    
    ImGui::ShowDemoWindow();
    ImGui::Render();
    
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
void Editor::CleanInterface() {
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    
    if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }
}
void Editor::DestroyInterface() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
void Editor::ProjectWindow() {
    if (ImGui::Begin("Project")) {
        
    } ImGui::End();
}
void Editor::ViewportWindow() {
    if (ImGui::Begin("Viewport")) {
        
    } ImGui::End();
}
void Editor::HierarchyWindow() {
    if (ImGui::Begin("Hierarchy")) {
        
    } ImGui::End();
}
void Editor::InspectorWindow() {
    if (ImGui::Begin("Inspector")) {
        
    } ImGui::End();
}
void Editor::ConsoleWindow() {
    if (ImGui::Begin("Console")) {
        
    } ImGui::End();
}
void Editor::MenuBar() {
    if (ImGui::BeginMainMenuBar())
    {
        ImGui::SetWindowFontScale(1.2);
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("New")) {
                
                ImGui::EndMenu();
            }
            if (ImGui::MenuItem("Open", "Ctrl+O")) {
                
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Open Recent"))
            {
                ImGui::MenuItem("fish_hat.c");
                ImGui::MenuItem("fish_hat.inl");
                ImGui::MenuItem("fish_hat.h");
                if (ImGui::BeginMenu("More.."))
                {
                    ImGui::MenuItem("Hello");
                    ImGui::MenuItem("Sailor");
                    if (ImGui::BeginMenu("Recurse.."))
                    {
                        ImGui::EndMenu();
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenu();
            }
            if (ImGui::MenuItem("Save", "Ctrl+S")) {
                ImGui::EndMenu();
            }
            if (ImGui::MenuItem("Save As..")) {
                ImGui::EndMenu();
            }
            ImGui::EndMenu();
        }
        
        
        
        
        
        //ImGui::EndMenu();
            if (ImGui::BeginMenu("Edit"))
            {
                if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
                
                if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}
                
                ImGui::Separator();
                if (ImGui::MenuItem("Cut", "CTRL+X")) {}
                
                if (ImGui::MenuItem("Copy", "CTRL+C")) {}
                
                if (ImGui::MenuItem("Paste", "CTRL+V")) {}
                
                ImGui::EndMenu();
            }
            ImGui::Separator();
            // ====
            
        
        ImGui::EndMainMenuBar();
    }
}
    
void Editor::ApplyDefaultTheme() {

    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding    = 10.0f;
    style.ChildRounding     = 10.0f;
    style.FrameRounding     = 8.0f;
    style.PopupRounding     = 10.0f;
    style.ScrollbarRounding = 12.0f;
    style.GrabRounding      = 8.0f;

    style.WindowPadding = ImVec2(12, 10);
    style.FramePadding  = ImVec2(10, 6);
    style.ItemSpacing   = ImVec2(10, 8);
    style.ItemInnerSpacing = ImVec2(8, 6);

    style.WindowBorderSize = 1.0f;
    style.FrameBorderSize  = 1.0f;
    style.PopupBorderSize  = 1.0f;

    ImVec4* c = style.Colors;

    auto V = [](float r, float g, float b, float a=1.0f){ return ImVec4(r,g,b,a); };

    // Backgrounds
    c[ImGuiCol_WindowBg]        = V(0.14f, 0.14f, 0.16f, 1.00f);
    c[ImGuiCol_ChildBg]         = V(0.20f, 0.20f, 0.23f, 1.00f);
    c[ImGuiCol_PopupBg]         = V(0.24f, 0.24f, 0.28f, 0.98f);

    // Borders / Separators
    c[ImGuiCol_Border]          = V(0.10f, 0.10f, 0.12f, 1.00f);
    c[ImGuiCol_Separator]       = V(0.18f, 0.18f, 0.21f, 1.00f);

    // Text
    c[ImGuiCol_Text]            = V(0.92f, 0.93f, 0.95f, 1.00f);
    c[ImGuiCol_TextDisabled]    = V(0.45f, 0.46f, 0.50f, 1.00f);

    // Frames
    c[ImGuiCol_FrameBg]         = V(0.24f, 0.24f, 0.28f, 1.00f);
    c[ImGuiCol_FrameBgHovered]  = V(0.34f, 0.34f, 0.40f, 1.00f);
    c[ImGuiCol_FrameBgActive]   = V(0.40f, 0.40f, 0.48f, 1.00f);

    // Buttons
    c[ImGuiCol_Button]          = V(0.24f, 0.24f, 0.28f, 1.00f);
    c[ImGuiCol_ButtonHovered]   = V(0.34f, 0.34f, 0.40f, 1.00f);
    c[ImGuiCol_ButtonActive]    = V(0.40f, 0.40f, 0.48f, 1.00f);

    // Headers
    c[ImGuiCol_Header]          = V(0.24f, 0.24f, 0.28f, 1.00f);
    c[ImGuiCol_HeaderHovered]   = V(0.34f, 0.34f, 0.40f, 1.00f);
    c[ImGuiCol_HeaderActive]    = V(0.40f, 0.40f, 0.48f, 1.00f);

    // Title bars
    c[ImGuiCol_TitleBg]         = V(0.14f, 0.14f, 0.16f, 1.00f);
    c[ImGuiCol_TitleBgActive]   = V(0.20f, 0.20f, 0.23f, 1.00f);

    // Scrollbar
    c[ImGuiCol_ScrollbarBg]     = V(0.14f, 0.14f, 0.16f, 1.00f);
    c[ImGuiCol_ScrollbarGrab]   = V(0.24f, 0.24f, 0.28f, 1.00f);
    c[ImGuiCol_ScrollbarGrabHovered] = V(0.34f, 0.34f, 0.40f, 1.00f);
    c[ImGuiCol_ScrollbarGrabActive]  = V(0.40f, 0.40f, 0.48f, 1.00f);

    // Бледно жёлтый
    ImVec4 Y  = V(0.96f, 0.90f, 0.62f, 1.00f);
    ImVec4 Yh = V(0.96f, 0.90f, 0.62f, 0.75f);
    ImVec4 Ya = V(0.96f, 0.90f, 0.62f, 0.25f);
    ImVec4 Ys = V(0.96f, 0.90f, 0.62f, 0.12f);

    c[ImGuiCol_CheckMark]          = Y;
    c[ImGuiCol_SliderGrab]         = Y;
    c[ImGuiCol_SliderGrabActive]   = Yh;

    c[ImGuiCol_TabHovered]         = Ya;
    c[ImGuiCol_TabActive]          = Ya;
    c[ImGuiCol_TabUnfocusedActive] = Ys;

    c[ImGuiCol_NavHighlight]       = Ya;
    c[ImGuiCol_TextSelectedBg]     = Ys;
    c[ImGuiCol_DragDropTarget]     = Y;

    // Plots
    c[ImGuiCol_PlotLines]          = Y;
    c[ImGuiCol_PlotLinesHovered]   = Yh;
    c[ImGuiCol_PlotHistogram]      = Y;
    c[ImGuiCol_PlotHistogramHovered]=Yh;
}
