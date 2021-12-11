#include "code/shared/app_factory.hpp"

namespace shared {
    // No CefApp for the renderer subprocess.
    CefRefPtr<CefApp> CreateRendererProcessApp() {
        std::cout<<"Create a renderer"<<std::endl;
        return NULL;
    }
} // namespace shared