#include <iostream>
#include <memory>

#include "Editor.hpp"
#include "Core/Core.hpp"

int main() {
    UNEVEN::Engine engine(std::make_unique<Editor>());
    return engine.Run();
}
