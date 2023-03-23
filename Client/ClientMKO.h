#pragma once



#include <QObject>
#include <QDebug>
#include <QTcpServer>

#include "rpc_mko_grpc.qpb.h"
#include "rpc_mko.qpb.h"

#include <grpcpp/grpcpp.h>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using namespace qtprotobuf::testrpc;



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

class EchoClient : public QObject {
    Q_OBJECT
	Q_PROPERTY(QString get_operators READ get_operators)
    Q_PROPERTY(EchoResponse* response READ response CONSTANT)
public:
    explicit EchoClient(QObject* parent = nullptr);
    ~EchoClient() = default;

    Q_INVOKABLE void request(EchoRequest *request);

    EchoResponse* response() const {
        qDebug() << "response()";
        return m_response.get();
    }

    QString get_operators();

private:
    std::unique_ptr<EchoServiceClient> m_client;
    std::unique_ptr<EchoResponse> m_response;
    std::vector<std::shared_ptr<Operators>> m_operators_list;
    void print_list_operators() const;
public slots:
    void add_operator_list(std::shared_ptr<Operators> list);
signals:
    void msg_changed();
    void send_operators(std::shared_ptr<Operators>);
};