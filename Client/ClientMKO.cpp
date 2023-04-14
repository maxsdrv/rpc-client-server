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
										  m_client(std::make_unique<EchoServiceClient>()),
										  m_response(std::make_unique<EchoResponse>()),
                                          model_operators(std::make_shared<OperatorsModel>())
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

    // Handle qml interface when user works with Operators
    connect(this, &EchoClient::operator_selected, this, &EchoClient::handle_operator_selected2);

}

void EchoClient::handle_subscription() {
    auto operators = QSharedPointer<Operators>(new Operators(subscription->read<Operators>())); 
    model_operators->append(operators);
}

void EchoClient::handle_operator_selected2(qtprotobuf::testrpc::Operators op) {
    qDebug() << "handle operator selected 2 called" << op.name() << op.command();

}


OperatorsModel* EchoClient::operators() {
	qDebug() << __func__ << "operators() called";
    return model_operators.get();
}
















