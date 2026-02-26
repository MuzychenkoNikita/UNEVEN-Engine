#include <iostream>
#include "Core.hpp"

namespace UNEVEN
{
int Engine::Run() {
    if (!m_project) return -1;
    
    m_project->OnStart();
    
    while (!m_project->m_close) {
        m_project->OnUpdate(0.0f);
    }
    
    m_project->OnStop();
    
    return 0;
}
}
