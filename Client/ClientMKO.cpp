#include "ClientMKO.h"

#include <QGrpcHttp2Channel>
#include <QGrpcInsecureCredentials>
#include <QAbstractGrpcChannel>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QLoggingCategory>
#include <QtConcurrent>


#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/grpcpp.h>

using namespace QtProtobuf;
using namespace qtprotobuf::testrpc;


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

QString EchoClient::add_operator_list(std::shared_ptr<Operators> list) {
	qDebug() << "add operator list";

	m_operators_list.push_back(list);

	list_name.append(list->name());	

	emit operators_list_changed();

	return "";
}

void EchoClient::get_operators() {
	// Clear the list of operators
	m_operators_list.clear();

	// Subscribe to updates for the list of operators
	auto lists =
	 	m_client->subscribeGet_operatorsUpdates(EchoRequest());

     // When an update is received, emit the send_operators signal with the new list
	QObject::connect(lists.get(), &QGrpcSubscription::updated, [=]()
					 {	
						std::shared_ptr<Operators> ref_operators = std::shared_ptr<Operators>(new Operators(lists->read<Operators>()));
						qDebug() << ref_operators->name() << ref_operators->command() << ref_operators->description();

						emit send_operators(ref_operators);
					 });
					 
	

	QObject::connect(this, &EchoClient::send_operators, this, &EchoClient::add_operator_list);
	
	
	qDebug() << "get_operators()";
	

	// lists->cancel();
}


void EchoClient::print_list_operators() const {
	qDebug() << "Test print list operators";
	for (const auto& i : m_operators_list) {
		qDebug() << i->name() << i->command() << i->description();
	}
}





































