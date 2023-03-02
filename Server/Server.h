#pragma once

#include <string>
#include <memory>
#include <QDebug>

#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

#include "rpc_mko.pb.h"
#include "rpc_mko.grpc.pb.h"

using qtprotobuf::testrpc::EchoService;
using qtprotobuf::testrpc::EchoRequest;
using qtprotobuf::testrpc::EchoResponse;
using grpc::ServerBuilder;
using grpc::Server;
using grpc::Status;
using grpc::ServerContext;

class MKOServer final : public EchoService::Service {
public:
	explicit MKOServer(const QString& db);
	~MKOServer() override { std::cout << "~Server()\n"; }

	Status Echo(ServerContext* context,  const EchoRequest* req, EchoResponse* res) override {
		qDebug() << "Request from client: " << req->message().c_str();
		std::string rev_message {};
		std::copy(req->message().rbegin(), req->message().rend(), std::back_inserter(rev_message));
		res->set_message(rev_message);

		return Status::OK;
	}

private:
	std::vector<EchoResponse> _res_list;
};





