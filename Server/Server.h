#pragma once

#include <string>
#include <memory>



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

class MKOServer final : public EchoService::Service {
public:
	explicit MKOServer();
	~MKOServer() override { std::cout << "~Server()\n"; }
	void run_server(const std::string& db_path);
private:

};

