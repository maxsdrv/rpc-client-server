#include "ClientMKO.h"

#include <QGrpcHttp2Channel>
#include <QGrpcInsecureCredentials>
#include <QAbstractGrpcChannel>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>

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

void ClientMKO::get_operators(EchoRequest* get_op) {
	qDebug() << "Get list operators: ";



	m_client->Echo(*get_op, m_response.get());
}

