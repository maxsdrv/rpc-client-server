#pragma once

#include <QDebug>
#include <memory>
#include <string>

#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

#include "rpc_mko.grpc.pb.h"
#include "rpc_mko.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerReaderWriter;
using qtprotobuf::testrpc::EchoRequest;
using qtprotobuf::testrpc::EchoResponse;
using qtprotobuf::testrpc::EchoService;
using qtprotobuf::testrpc::Operators;

class MKOServer final : public EchoService::Service {
public:
  explicit MKOServer(const QString &db);
  ~MKOServer() override { std::cout << "~Server()\n"; }

  Status Echo(ServerContext *context, const EchoRequest *req,
              EchoResponse *res) override {
    qDebug() << "Request from client: " << req->message().c_str();

    std::string prefix("Echo: ");
    res->set_message(prefix + req->message());

    return Status::OK;
  }

  Status get_operators(ServerContext* context, const EchoRequest* request,
                       grpc::ServerWriter<Operators>* writer) override {
      qDebug() << "Test stream operators:";

      Operators op1;
      op1.set_name("Operator1");
      op1.set_command("cmd1");
      op1.add_description("desc1.1");
      op1.add_description("desc1.2");
      op1.add_description("desc1.3");

      Operators op2;
      op2.set_name("Operator2");
      op2.set_command("cmd2");
      op2.add_description("desc2.1");
      op2.add_description("desc2.2");
      op2.add_description("desc2.3");


      writer->Write(op1);
      writer->Write(op2);

      return Status::OK;
  }

private:
  std::vector<EchoResponse> _res_list;
};
