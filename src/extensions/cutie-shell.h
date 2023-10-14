#pragma once

#include "wayland-util.h"

#include <QtWaylandClient/QWaylandClientExtensionTemplate>
#include <QtWaylandClient/QtWaylandClient>

#include <QtQml/QQmlEngine>

#include "qwayland-cutie-shell-private.h"

class CutieShell : public QWaylandClientExtensionTemplate<CutieShell>
	, public QtWayland::cutie_shell_private

{
	Q_OBJECT
public:
	CutieShell(QQmlEngine *engine = nullptr);
	Q_INVOKABLE void execApp(const QString &path);

    static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
	QQmlEngine *m_engine;
};
