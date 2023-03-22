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
#include <grpcpp/grpcpp.h>


using namespace QtProtobuf;

ClientMKO::ClientMKO(QObject *parent) : QObject(parent),
										m_client(new EchoServiceClient),
										m_response(new EchoResponse)
{

	auto channel = std::shared_ptr<QAbstractGrpcChannel>(new QGrpcHttp2Channel(QUrl("http://localhost:65000"),
																			   QGrpcInsecureChannelCredentials() |
																				   QGrpcInsecureCallCredentials()));
	m_client->attachChannel(channel);
	m_client->attachChannel(std::shared_ptr<QAbstractGrpcChannel>(
		new QGrpcHttp2Channel(QUrl("http://localhost:65000"),
							  QGrpcInsecureChannelCredentials() |
								  QGrpcInsecureCallCredentials())));
}
void ClientMKO::request(EchoRequest *req) {
	qDebug() << "Request message: " << req->message();
	m_client->Echo(*req, m_response.get());
}

void ClientMKO::get_operators(EchoRequest* get_op) {
	qDebug() << "Get list operators: ";
	m_client->Echo(*get_op, m_response.get());
}

EchoClient::EchoClient(QObject *parent) : QObject(parent),
										  m_client(new EchoServiceClient),
										  m_response(new EchoResponse)
{
	auto channel = std::shared_ptr<QAbstractGrpcChannel>(new QGrpcHttp2Channel(QUrl("http://localhost:65000"),
																			QGrpcInsecureChannelCredentials() |
																			QGrpcInsecureCallCredentials()));
	m_client->attachChannel(channel);
	m_client->attachChannel(std::shared_ptr<QAbstractGrpcChannel>(
	new QGrpcHttp2Channel(QUrl("http://localhost:65000"),
							  QGrpcInsecureChannelCredentials() |
								  QGrpcInsecureCallCredentials())));

	connect(this, &EchoClient::msg_changed, []() {
		qDebug() << "Message changed!";
	});
}

void EchoClient::set_msg(const QString& message) {
	m_response->setMessage(message);
    emit msg_changed();
}

QString EchoClient::Echo() const {
	return m_response->message();
}


QString EchoClient::get_operators() {
/*
 QString EchoClient::get_operators()
{
    if (!m_client) {
        // Create the client if it doesn't exist
        m_client = std::make_unique<EchoServiceClient>(this);
    }

    // Subscribe to the operators update stream
    const auto subscription = m_client->subscribeGet_operatorsUpdates(qtprotobuf::testrpc::EchoRequest());

    // Wait for the initial response
    subscription->waitForReady();

    // Retrieve the operators from the initial response
    const QStringList operators = subscription->value().operators();

    // Return the operators as a single string
    return operators.join(", ");
}
*
 */
	const auto subscription = m_client->subscribeGet_operatorsUpdates(EchoRequest());

}































