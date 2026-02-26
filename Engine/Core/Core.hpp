#pragma once
#include <memory>

namespace UNEVEN
{
class Project {
public:
    virtual void OnStart() {}
    virtual void OnUpdate(float dt) {}
    virtual void OnStop() {}
    
public:
    bool m_close = false;
    
private:
    
    
};

class Engine {
public:
    explicit Engine(std::unique_ptr<Project> project)
    : m_project(std::move(project)) {}
    
    int Run();
    
public:
    bool m_close = false;
    
private:
    std::unique_ptr<Project> m_project;
    
};
}
