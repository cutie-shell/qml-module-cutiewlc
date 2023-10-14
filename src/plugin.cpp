#include "plugin.h"
#include "extensions/cutie-shell.h"

void CutieWlcPlugin::registerTypes(const char *uri) {
    qmlRegisterSingletonType<CutieShell>(uri, 1, 0, "CutieWlc", &CutieShell::provider);
}