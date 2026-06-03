#include <slang/slang.h>
#include <iostream>
#include <fstream>

inline void CompileShader(const char* name)
{
    slang::IGlobalSession* globalSession = nullptr;
    slang::createGlobalSession(&globalSession);

    slang::TargetDesc targetDesc = {};
    targetDesc.format = SLANG_SPIRV;
    
    const char* searchPaths[] = { "shaders/" };

    slang::SessionDesc sessionDesc = {};
    sessionDesc.targets = &targetDesc;
    sessionDesc.targetCount = 1;
    sessionDesc.searchPaths = searchPaths;
    sessionDesc.searchPathCount = 1;

    slang::ISession* session = nullptr;
    globalSession->createSession(sessionDesc, &session);

    slang::IModule* module = nullptr;
    slang::IBlob* diagnostics = nullptr;

    module = session->loadModule(name, &diagnostics);

    if (diagnostics)
    {
        std::cout << (char*)diagnostics->getBufferPointer() << std::endl;
    }

    if (!module)
    {
        std::cout << "Failed to load shader: " << name << std::endl;
        return;
    }

    // 5. Find entry point
    slang::IEntryPoint* entryPoint = nullptr;
    module->findEntryPointByName("vertMain", &entryPoint);
    module->findEntryPointByName("fragMain", &entryPoint);

    if (!entryPoint)
    {
        std::cout << "Entry point 'main' not found\n";
        return;
    }

    // 6. Link program
    slang::IComponentType* program = nullptr;
    slang::IComponentType* components[] = { module, entryPoint };

    session->createCompositeComponentType(
        components, 2, &program);

    // 7. Get SPIR-V
    slang::IBlob* spirvCode = nullptr;

    program->getEntryPointCode(
        0, 0, &spirvCode, nullptr);

    if (!spirvCode)
    {
        std::cout << "Failed to compile SPIR-V\n";
        return;
    }

    // 8. Save to file
    std::string outputFile = std::string("shaders/") + name + ".spv";

    std::ofstream out(outputFile, std::ios::binary);
    out.write(
        (char*)spirvCode->getBufferPointer(),
        spirvCode->getBufferSize()
    );
    out.close();

    std::cout << "Compiled: " << outputFile << std::endl;
}
