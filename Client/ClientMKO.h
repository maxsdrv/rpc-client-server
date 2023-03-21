#pragma once



#include <QObject>
#include <QDebug>
#include <QTcpServer>

#include "profile.h"
#include "rpc_mko.qpb.h"
#include "rpc_mko_grpc.qpb.h"

#include <grpcpp/grpcpp.h>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using namespace qtprotobuf::testrpc;


// using qtprotobuf::testrpc::EchoRequest;
// using qtprotobuf::testrpc::EchoResponse;
// using qtprotobuf::testrpc::Operators;



class ClientMKO : public QObject {
    Q_OBJECT
    Q_PROPERTY(EchoResponse* response READ response CONSTANT)
    Q_PROPERTY(EchoResponse* array_op READ array_op CONSTANT)

public:
  explicit ClientMKO(QObject *parent = nullptr);
  ~ClientMKO() override { qDebug() << "~ClientMKO()"; }

  Q_INVOKABLE void request(EchoRequest* req);
  Q_INVOKABLE void get_operators(EchoRequest* get_op);

  qtprotobuf::testrpc::EchoResponse* response() const {
			qDebug() << "Response message: " << m_response->message();
      return m_response.get();
  }
  qtprotobuf::testrpc::EchoResponse* array_op() const {
      qDebug() <<  "List operators: ";
      return m_response.get();
  }
  

private:

    std::unique_ptr<EchoServiceClient> m_client;
    std::unique_ptr<EchoResponse> m_response;
};

// class EchoClient {
// public:
//     EchoClient(std::shared_ptr<Channel> channel) : stub_(EchoService::NewStub(channel)) {}
// private:
//     std::unique_ptr<EchoService::Stub> stub_;
// };