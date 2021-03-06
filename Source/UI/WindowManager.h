#pragma once

#include <Urho3D/Urho3DAll.h>
#include "BaseWindow.h"

using namespace Urho3D;

class WindowManager : public Object
{
    URHO3D_OBJECT(WindowManager, Object);

public:
    /// Construct.
    WindowManager(Context* context);

    virtual ~WindowManager();

    void Dispose();

    bool IsWindowOpen(String windowName);
    bool IsConsoleVisible();

private:

    void RegisterAllFactories();

    void SubscribeToEvents();

    void HandleOpenWindow(StringHash eventType, VariantMap& eventData);
    void HandleCloseWindow(StringHash eventType, VariantMap& eventData);
    void HandleCloseAllWindows(StringHash eventType, VariantMap& eventData);
    void HandleUpdate(StringHash eventType, VariantMap& eventData);

    void CloseWindow(String windowName);

    List<SharedPtr<Object>> _windowList;

    HashMap<String, bool> _persistentWindows;
    List<String> _openedWindows;

    bool _consoleVisible;
    List<String> _closeQueue;
};