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
  ~EchoClient() override { 
    qDebug() << "~EchoClient()"; 
  };

  Q_INVOKABLE qtprotobuf::testrpc::Operators on_clicked_operator(int index) {
      return model_operators->at(index); // !!!! ЕЛИ ВОЗВРАЩАТЬ УКАЗАТЕЛЬ БУДЕ SEGMENTATION FAULT
  }

  OperatorsModel *operators(); 

private:
  std::unique_ptr<EchoServiceClient> m_client;
  std::unique_ptr<EchoResponse> m_response;
  std::shared_ptr<QtProtobuf::QGrpcSubscription> subscription;
  std::shared_ptr<OperatorsModel> model_operators;

public slots:
  void handle_operator_selected2(qtprotobuf::testrpc::Operators op); 
  void handle_subscription();
signals:
  void operator_selected(qtprotobuf::testrpc::Operators op);
  void run_button_execute();
};

}

Q_DECLARE_METATYPE(qtprotobuf::testrpc::OperatorsModel*)




