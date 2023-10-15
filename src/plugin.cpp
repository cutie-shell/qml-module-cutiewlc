#include "plugin.h"
#include "extensions/cutie-shell.h"

void CutieWlcPlugin::registerTypes(const char *uri) {
    CutieShell *cutieShell = new CutieShell();
    qmlRegisterSingletonType<CutieShell>(uri, 1, 0, "CutieWlc", 
        [cutieShell](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        return cutieShell;
    });
}