#include "ClientMKO.h"

#include <QGrpcHttp2Channel>
#include <QGrpcInsecureCredentials>
#include <QAbstractGrpcChannel>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


using namespace QtProtobuf;

ClientMKO::ClientMKO(QObject *parent) : QObject(parent),
																				m_client(new EchoServiceClient),
																				m_response(new EchoResponse) {

	auto channel = std::shared_ptr<QAbstractGrpcChannel>(new QGrpcHttp2Channel(QUrl("http://localhost:65000"),
																																						 QGrpcInsecureChannelCredentials() |
																																							 QGrpcInsecureCallCredentials()));
	m_client->attachChannel(channel);
	m_client->attachChannel(std::shared_ptr<QAbstractGrpcChannel>(
					new QGrpcHttp2Channel(QUrl("http://localhost:65000"),
																QGrpcInsecureChannelCredentials() |
																QGrpcInsecureCallCredentials())
					));

}
void ClientMKO::request(EchoRequest *req) {
	qDebug() << "Request message: " << req->message();
	m_client->Echo(*req, m_response.get());
}

