#include <extensions/cutie-shell.h>

CutieShell::CutieShell(QQmlEngine *engine)
    : QWaylandClientExtensionTemplate(1) {
    m_engine = engine;
}

void CutieShell::execApp(const QString &path)
{
	QtWayland::cutie_shell_private::exec_app(path);
}

QObject *CutieShell::provider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(scriptEngine);
    return new CutieShell(engine);
}