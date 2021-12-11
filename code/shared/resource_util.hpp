#ifndef CEF_EXAMPLES_SHARED_RESOURCE_UTIL_H_
#define CEF_EXAMPLES_SHARED_RESOURCE_UTIL_H_

#include <string>

#include "include/cef_resource_handler.h"
#include "include/cef_stream.h"

namespace shared {

    // Origin for loading local test resources.
    extern const char kTestOrigin[];
    
    // Retrieve the directory containing resource files on linux and macOS.
    bool GetResourceDir(std::string& dir);

    // Returns the resource path for |url|. Removes fragment and/or quer component
    // if it exists. The URL must start with kTestOrigin.
    std::string GetResourcePath(const std::string& url);

    // Determine the mime type based on |resource_path|'s file extension
    std::string GetMimeType(const std::string& resource_path);

    // Retrieve |resource_path| contents as a std::string. Returns false if the
    // resource is not found.
    bool GetResourceString(const std::string& resource_path, std::string& out_data);

    // Retrieve |resource_path| contents as a CefStreamReader. Returns NULL if the
    // resource is not found.
    CefRefPtr<CefStreamReader> GetResourceReader(const std::string& resource_path);

    // Retrieve |resource_path| contents as a CefResourceHandler. Returns NULL if
    // the resource is not found.
    CefRefPtr<CefResourceHandler> GetResourceHandler(const std::string& resource_path);

} // namespace shared
#endif // SHARED_RESOURCE_UTIL_H_