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
  Q_PROPERTY(QStringList operators_list READ operators_list)
  Q_PROPERTY(qtprotobuf::testrpc::OperatorsModel *operators READ operators CONSTANT)

public:
  explicit EchoClient(QObject *parent = nullptr);
  ~EchoClient() override = default;

  Q_INVOKABLE void request(EchoRequest *request);
  Q_INVOKABLE void get_operators();
  Q_INVOKABLE void get_result();

  [[nodiscard]] EchoResponse *response() const; 
  [[nodiscard]] QStringList operators_list() const; 
  OperatorsModel *operators(); 

private:
  std::unique_ptr<EchoServiceClient> m_client;
  std::unique_ptr<EchoResponse> m_response;
  std::vector<std::shared_ptr<Operators>> m_operators_list;
  QStringList list_name;
  OperatorsModel model_operators;


public slots:
  void add_operator_list(std::shared_ptr<Operators> list);
  void handle_operator_selected(const QString& name);
signals:
  void send_operators(std::shared_ptr<Operators>);
  void operator_selected(QString name);

};

}

Q_DECLARE_METATYPE(qtprotobuf::testrpc::OperatorsModel*)




