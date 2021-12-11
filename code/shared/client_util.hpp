#ifndef CEF_EXAMPLES_SHARED_CLIENT_BASE_H_
#define CEF_EXAMPLES_SHARED_CLIENT_BASE_H_

#include "include/cef_client.h"

namespace shared {
    
    void OnTitleChange(CefRefPtr<CefBrowser> browser, const CefString& title);

    void OnAfterCreated(CefRefPtr<CefBrowser> browser);
    bool DoClose(CefRefPtr<CefBrowser> browser);
    void OnBeforeClose(CefRefPtr<CefBrowser> browser);

    void PlatformTitleChange(CefRefPtr<CefBrowser> browser, const CefString& title);

    std::string DumpRequestContents(CefRefPtr<CefRequest> request);
} // namespace shared

#endif 