#include "ServerMKO.h"

#include <QGrpcHttp2Channel>
#include <QGrpcInsecureCredentials>
#include <QAbstractGrpcChannel>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

using namespace QtProtobuf;

ServerMKO::ServerMKO(QObject *parent) : QObject(parent) {
    m_client->attachChannel(std::shared_ptr<QAbstractGrpcChannel>(
            new QGrpcHttp2Channel(QUrl("http://localhost:65000"),
                                  QGrpcInsecureChannelCredentials() |
                                  QGrpcInsecureCallCredentials())
            ));
}
void ServerMKO::request(EchoRequest* req) {
    m_client->Echo(*req, m_response.get());
}

int main(int argc, char **argv) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject* obj, const QUrl& objUrl) {
      if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);

  QtProtobuf::qRegisterProtobufTypes();
  qmlRegisterSingletonType<ServerMKO>("qtprotobuf.test_rpc", 1, 0, "ServerMKO",
                                      [](QQmlEngine* engine,
                                      QJSEngine*) -> QObject* {
      static ServerMKO server_engine;
      engine->setObjectOwnership(&server_engine, QQmlEngine::CppOwnership);
      return &server_engine;
  });

  engine.load(url);

  return app.exec();
}
