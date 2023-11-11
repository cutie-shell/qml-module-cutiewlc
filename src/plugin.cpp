#include "plugin.h"
#include <wayland-cutie-shell.h>
#include <qt6-foreign-toplevel-management.h>

void CutieWlcPlugin::registerTypes(const char *uri) {
    CutieShell *cutieShell = new CutieShell();
    qmlRegisterSingletonType<CutieShell>(uri, 1, 0, "CutieWlc", 
        [cutieShell](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        return cutieShell;
    });

    ForeignToplevelManagerV1 *foreignToplevelManager = new ForeignToplevelManagerV1();
    qmlRegisterSingletonType<ForeignToplevelManagerV1>(uri, 1, 0, "ForeignToplevelManagerV1", 
        [foreignToplevelManager](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        return foreignToplevelManager;
    });

    qmlRegisterUncreatableType<ForeignToplevelHandleV1>(uri, 1, 0, "ForeignToplevelHandleV1",
        "This type is used to interact with a foreign toplevel. Use ForeignToplevelManagerV1 to retrieve and detect these toplevels.");
}