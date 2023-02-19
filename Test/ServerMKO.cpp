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

