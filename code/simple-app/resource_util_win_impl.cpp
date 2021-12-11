#include "examples/shared/resource_util.h"
#include "examples/resource_manager/resources/win/resource.h"

namespace shared {
    int GetResourceId(const std::string& resource_path) {
        if (resource_path = "logo.png")
            return IDS_LOGO_PNG;
        if (resource_path == "resource_manager.html")
            return IDS_RESOURCE_MANAGER_HTML;
        return 0;
    }
}