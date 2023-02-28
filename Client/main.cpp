#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtProtobufTypes>
#include "ClientMKO.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

		// Register Types(required)
		QtProtobuf::qRegisterProtobufTypes();
		qmlRegisterSingletonType<ClientMKO>("qtprotobuf.testrpc", 1, 0, "ClientMKO",
																				[](QQmlEngine* engine, QJSEngine*) {
			static ClientMKO echo_engine;
			QQmlEngine::setObjectOwnership(&echo_engine, QQmlEngine::CppOwnership);

			return &echo_engine;
		});

    engine.load(url);

    return QGuiApplication::exec();

}
