#pragma once
#include <memory>

#include <vector>
#include <map>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "Renderer/Shaders/Shader.hpp"

#if defined(__INTELLISENSE__) || !defined(USE_CPP20_MODULES)
#define VULKAN_HPP_NO_STRUCT_CONSTRUCTORS
#include <vulkan/vulkan_raii.hpp>
#else
import vulkan_hpp;
#endif
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

constexpr uint32_t WIDTH = 800;
constexpr uint32_t HEIGHT = 600;

const std::vector<char const*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
constexpr bool enableValidationLayers = false;
#else
constexpr bool enableValidationLayers = true;
#endif

static VKAPI_ATTR vk::Bool32 VKAPI_CALL debugCallback(vk::DebugUtilsMessageSeverityFlagBitsEXT       severity,
                                                      vk::DebugUtilsMessageTypeFlagsEXT              type,
                                                      const vk::DebugUtilsMessengerCallbackDataEXT * pCallbackData,
                                                      void *                                         pUserData)
{
  std::cerr << "validation layer: type " << to_string(type) << " msg: " << pCallbackData->pMessage << std::endl;

  return vk::False;
}

namespace UNEVEN
{
struct Context {
    GLFWwindow* window = nullptr;
    //Renderer renderer;
    //Input input;
};

class Project {
public:
    virtual ~Project() = default;
    virtual void OnStart(Context ctx) {}
    virtual void OnUpdate(Context ctx, float dt) {}
    virtual void OnStop(Context ctx) {}
    
public:
    
private:
    
    
};

class Engine {
public:
    explicit Engine(std::unique_ptr<Project> project)
    : m_project(std::move(project)) {}
    
    int Run();
    
public:
    void listSupportedExtensions();
    
private:
    void initWindow();
    void initVulkan();
    void cleanup();
    
    void createInstance();
    void setupDebugMessenger();
    void createSurface();
    void pickPhysicalDevice();
    void createLogicalDevice();
    void createSwapChain();
    void createImageViews();
    void createGraphicsPipeline();
    
    
    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredInstanceExtensions();
    bool isDeviceSuitable( vk::raii::PhysicalDevice const & physicalDevice );
    
    vk::SurfaceFormatKHR chooseSwapSurfaceFormat(std::vector<vk::SurfaceFormatKHR> const &availableFormats);
    vk::PresentModeKHR chooseSwapPresentMode(std::vector<vk::PresentModeKHR> const &availablePresentModes);
    vk::Extent2D chooseSwapExtent(vk::SurfaceCapabilitiesKHR const &capabilities);
    uint32_t chooseSwapMinImageCount(vk::SurfaceCapabilitiesKHR const &surfaceCapabilities);
    
private:
    std::unique_ptr<Project>    m_project;
    Context                     m_ctx;
    
    vk::raii::Context                   m_vkContext;
    vk::raii::Instance                  m_instance{ nullptr };
    vk::raii::DebugUtilsMessengerEXT    debugMessenger = nullptr;
    vk::raii::SurfaceKHR                surface = nullptr;
    
    vk::raii::PhysicalDevice    physicalDevice = nullptr;
    vk::raii::Device            device = nullptr;
    vk::PhysicalDeviceFeatures  deviceFeatures;
    vk::raii::Queue             queue = nullptr;
    
    vk::raii::SwapchainKHR      swapChain = nullptr;
    std::vector<vk::Image>      swapChainImages;
    vk::SurfaceFormatKHR        swapChainSurfaceFormat;
    vk::Extent2D                swapChainExtent;
    std::vector<vk::raii::ImageView> swapChainImageViews;
    
    std::vector<const char*> requiredDeviceExtension = {
        vk::KHRSwapchainExtensionName
    };
    
    static std::vector<char> readFile(const std::string& filename);
    [[nodiscard]] vk::raii::ShaderModule createShaderModule(const std::vector<char> &code) const;
    vk::raii::PipelineLayout pipelineLayout = nullptr;
    vk::raii::Pipeline graphicsPipeline = nullptr;
    
};
}
