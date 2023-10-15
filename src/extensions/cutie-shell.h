#pragma once

#include "wayland-util.h"

#include <QtWaylandClient/QWaylandClientExtensionTemplate>
#include <QtWaylandClient/QtWaylandClient>

#include <QtQml/QQmlEngine>

#include "qwayland-cutie-shell-private.h"

class Q_WAYLANDCLIENT_EXPORT CutieShell 
	: public QWaylandClientExtensionTemplate<CutieShell>
	, public QtWayland::cutie_shell_private {
	Q_OBJECT
public:
	CutieShell();
	Q_INVOKABLE void execApp(const QString &path);
};
