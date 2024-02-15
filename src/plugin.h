#pragma once
#include <QDebug>
#include <QtQuick>
#include <QtQml/qqml.h>
#include <QtQml/QQmlExtensionPlugin>

class CutieWlcPlugin : public QQmlExtensionPlugin {
	Q_OBJECT
	Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid FILE
			  "cutiewlc.json")
	void registerTypes(const char *uri);
};