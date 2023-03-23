#include "ClientMKO.h"

#include <QGrpcHttp2Channel>
#include <QGrpcInsecureCredentials>
#include <QAbstractGrpcChannel>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QLoggingCategory>


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

void EchoClient::request(EchoRequest *request) {
	qDebug() << "request()" << request->message();
	m_client->Echo(*request, m_response.get());
}

void EchoClient::add_operator_list(std::shared_ptr<Operators> list) {
	qDebug() << "add operator list";
	qDebug() << list->name();
	m_operators_list.push_back(list);
	print_list_operators();
}

QString EchoClient::get_operators() {
	m_operators_list.clear();

	auto lists =
	 	m_client->subscribeGet_operatorsUpdates(EchoRequest());

	QObject::connect(lists.get(), &QGrpcSubscription::updated, [=]()
					 {	
						std::shared_ptr<Operators> ref_operators = std::shared_ptr<Operators>(new Operators(lists->read<Operators>()));
						emit send_operators(ref_operators);
					 });

	QObject::connect(this, &EchoClient::send_operators, this, &EchoClient::add_operator_list);

	qDebug() << "get_operators()";

	return "OK";
}

void EchoClient::print_list_operators() const {
	qDebug() << "Test print list operators";
	for (const auto& i : m_operators_list) {
		qDebug() << i->name() << i->command() << i->description();
	}
}






























