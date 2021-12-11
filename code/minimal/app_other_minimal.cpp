#include "code/shared/app_factory.hpp"

namespace shared {
    CefRefPtr<CefApp> CreateOtherProcessApp() {
        std::cout<<"Create other process app"<<std::endl;
        return NULL;
    }
} // namespace shared