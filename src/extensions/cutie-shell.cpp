#include <extensions/cutie-shell.h>

CutieShell::CutieShell()
    : QWaylandClientExtensionTemplate(1) {
}

void CutieShell::execApp(const QString &path)
{
    if (isActive()) {
	    QtWayland::cutie_shell_private::exec_app(path);
    } else {
        qWarning() << "CutieShell protocol is not activated!";
    }
}