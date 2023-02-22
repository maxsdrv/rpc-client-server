#pragma once

#include <string>
#include <memory>

#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>


#include "server.grpc.pb.h"
#include "server.grpc.pb.h"

#include "test_rpc_grpc.qpb.h"
#include "test_rpc.qpb.h"

using grpc::Server;
using grpc::ServerContext;
using grpc::ServerBuilder;

using namespace servermko;
using servermko::ServerResponse;

class MKOServer final : public ServerTestMKO::Service {
public:
	explicit MKOServer();
	~MKOServer() override { std::cout << "~Server()\n"; }
	void run_server(const std::string& db_path);
private:

};

