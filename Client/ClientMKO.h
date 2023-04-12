#pragma once

#include <QObject>
#include <QDebug>
#include <QGrpcSubscription>

#include "rpc_mko_grpc.qpb.h"
#include "rpc_mko.qpb.h"

#include <grpcpp/grpcpp.h>

#include "OperatorsListModel.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

namespace qtprotobuf::testrpc {

using OperatorsModel = OperatorsListModel<qtprotobuf::testrpc::Operators>;

class EchoClient : public QObject {
Q_OBJECT
  Q_PROPERTY(qtprotobuf::testrpc::OperatorsModel *operators READ operators CONSTANT)

public:
  explicit EchoClient(QObject *parent = nullptr);
  ~EchoClient() override = default;

  Q_INVOKABLE void request(qtprotobuf::testrpc::EchoRequest *request);
  Q_INVOKABLE void get_result();

  OperatorsModel *operators(); 

private:
  std::unique_ptr<EchoServiceClient> m_client;
  std::unique_ptr<EchoResponse> m_response;
  std::vector<std::shared_ptr<Operators>> m_operators_list;
  std::shared_ptr<QtProtobuf::QGrpcSubscription> subscription;
  OperatorsModel model_operators;

public slots:
  void handle_operator_selected(const QString& name);
  void handle_operator_selected2(QObject* obj);
  void handle_subscription();
signals:
  void send_operators(std::shared_ptr<Operators>);
//  void operator_selected(QString name);
  void operator_selected(QObject* obj);

};

}

Q_DECLARE_METATYPE(qtprotobuf::testrpc::OperatorsModel*)




