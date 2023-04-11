#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtProtobufTypes>
#include <QStringListModel>
#include <QMetaType>

#include "ClientMKO.h"

using namespace qtprotobuf::testrpc;

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

	// Register Types(required)
	QtProtobuf::qRegisterProtobufTypes();

    qmlRegisterUncreatableType<OperatorsModel>("echoClient", 1, 0, "OperatorsModel", "");

    qmlRegisterSingletonType<EchoClient>("echoClient", 1, 0, "EchoClient",
                                        [](QQmlEngine* engine, QJSEngine*) {
        static EchoClient client;

        QQmlEngine::setObjectOwnership(&client, QQmlEngine::CppOwnership);

        return &client;

    });

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main_window.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    engine.load(url);

    return QGuiApplication::exec();


}
