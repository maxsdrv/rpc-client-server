#include "ClientMKO.h"

#include <QGrpcHttp2Channel>
#include <QGrpcInsecureCredentials>
#include <QAbstractGrpcChannel>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QLoggingCategory>
#include <QtConcurrent>
#include <algorithm>


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

    subscription =
        m_client->subscribeGet_operatorsUpdates(EchoRequest());

    connect(subscription.get(), &QGrpcSubscription::updated,
            this, &EchoClient::handle_subscription);
    connect(subscription.get(), &QGrpcSubscription::error, this, [=](QGrpcStatus status) {
        qDebug() << status.message();
    });
}


void EchoClient::handle_subscription() {
    m_operators_list.push_back(std::shared_ptr<Operators>(new Operators(subscription->read<Operators>())));
    model_operators.append(m_operators_list.back().get());
}

void EchoClient::handle_operator_selected(const QString& name) {
	qDebug() << "Selected operator: " << name;
	
    auto shared_ptr_itr = std::find_if(m_operators_list.begin(),
                                        m_operators_list.end(),
                                        [&](const std::shared_ptr<Operators>& optr) {
        return optr->name() == name;
    });

    if (shared_ptr_itr != m_operators_list.end()) {
        m_client->calculations(shared_ptr_itr->get(), m_response.get());
    }
    else {
        qDebug() << "Error, Operator does not exist";
    }
}
void EchoClient::handle_operator_selected2(QObject* obj) {
    qDebug() << "Selected operator object" << obj;

}


OperatorsModel* EchoClient::operators() {
	qDebug() << __func__ << "operators() called";
	return &model_operators;
}

void EchoClient::request(EchoRequest *request) {
	qDebug() << "request()" << request->message();
	m_client->Echo(*request, m_response.get());
}

void EchoClient::get_result() {

}













