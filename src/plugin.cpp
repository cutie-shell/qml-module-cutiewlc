#include "plugin.h"
#include <wayland-cutie-shell.h>
#include <qt6-foreign-toplevel-management.h>

void CutieWlcPlugin::registerTypes(const char *uri) {
    qmlRegisterType<CutieShell>(uri, 1, 0, "CutieWlc");
    qmlRegisterType<ForeignToplevelManagerV1>(uri, 1, 0, "ForeignToplevelManagerV1");
    qmlRegisterUncreatableType<ForeignToplevelHandleV1>(uri, 1, 0, "ForeignToplevelHandleV1",
        "This type is used to interact with a foreign toplevel. Use ForeignToplevelManagerV1 to retrieve and detect these toplevels.");
}