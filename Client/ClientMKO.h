#pragma once

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QFutureWatcher>

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
  Q_PROPERTY(EchoResponse *response READ response CONSTANT)
  Q_PROPERTY(QStringList operators_list READ operators_list NOTIFY operators_list_changed)
  Q_PROPERTY(qtprotobuf::testrpc::OperatorsModel *operators READ operators CONSTANT)

public:
  explicit EchoClient(QObject *parent = nullptr);
  ~EchoClient() override = default;

  Q_INVOKABLE void request(EchoRequest *request);

  EchoResponse *response() const {
	  qDebug() << "response()";
	  return m_response.get();
  }

  Q_INVOKABLE void get_operators();

  QStringList operators_list() const {
	  return list_name;
  }

  OperatorsModel *operators() {
	  qDebug() << __func__ << "operators() called";
	  return &model_operators;
  }
private:
  std::unique_ptr<EchoServiceClient> m_client;
  std::unique_ptr<EchoResponse> m_response;
  std::vector<std::shared_ptr<Operators>> m_operators_list;
  QStringList list_name;
  OperatorsModel model_operators;

  void print_list_operators() const;

public slots:
  QString add_operator_list(std::shared_ptr<Operators> list);

signals:
  void msg_changed();
  void send_operators(std::shared_ptr<Operators>);
  void operators_list_changed();

};
}

Q_DECLARE_METATYPE(qtprotobuf::testrpc::OperatorsModel*)




