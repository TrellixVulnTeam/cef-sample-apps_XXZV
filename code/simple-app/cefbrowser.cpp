#include "code/simple-app/cefclient.hpp"
#include "code/shared/app_factory.hpp"
#include "code/shared/browser_util.hpp"
#include "code/shared/resource_util.hpp"

#include <iostream>

namespace resource_manager {
    namespace {
        std::string GetStartupURL() {
            return shared::kTestOrigin + std::string("resource_manager.html");
        }
    } // namespace
    class BrowserApp : public CefApp, public CefBrowserProcessHandler {
        public:
            BrowserApp() {}

            // CefAPP methods:
            CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() OVERRIDE {
                return this;
            }

            void OnBeforeCommandLineProcessing(
                const CefString& process_type,
                CefRefPtr<CefCommandLine> command_line) OVERRIDE {
                // Command-line flags can be modified in this callback
                // |process_type| is empty for the browser process.
                if (process_type.empty()) {
#if defined(OS_MACOSX)
                // Disable the macOS keychain prompt. Cookies will not be encrypted.
                command_line->AppendSwitch("use-mock-keychain");
#endif
                }
            }
            void OnContextInitialized() OVERRIDE {
                // Create the browser window
                shared::CreateBrowser(new Client(), GetStartupURL(), CefBrowserSettings());
            }

        private:
            IMPLEMENT_REFCOUNTING(BrowserApp);
            DISALLOW_COPY_AND_ASSIGN(BrowserApp);
    };
} // namespace resource_manager

namespace shared{
    CefRefPtr<CefApp> CreateBrowserProcessApp() {
        std::cout<<"creating browser a app"<<std::endl;
        return new resource_manager::BrowserApp();
    }
} // namespace shared
