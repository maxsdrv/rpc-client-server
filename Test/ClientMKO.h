#pragma once

#include <QObject>
#include <QDebug>
#include <QTcpServer>

#include "profile.h"
#include "test_rpc.qpb.h"
#include "test_rpc_grpc.qpb.h"

using namespace qtprotobuf::testrpc;

class ClientMKO : public QObject {
    Q_OBJECT
    Q_PROPERTY(qtprotobuf::testrpc::EchoResponse* response READ response CONSTANT)
public:
  explicit ClientMKO(QObject *parent = nullptr);
  ~ClientMKO() override { qDebug() << "ClientMKO()"; }

  Q_INVOKABLE void request(qtprotobuf::testrpc::EchoRequest* req);

  qtprotobuf::testrpc::EchoResponse* response() const {
      return m_response.get();
  }

private:
    std::unique_ptr<qtprotobuf::testrpc::EchoServiceClient> m_client;
    std::unique_ptr<qtprotobuf::testrpc::EchoResponse> m_response;
};
