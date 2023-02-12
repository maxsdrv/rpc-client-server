#include <iostream>
#include <chrono>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>

#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <JsonParser.h>
#ifdef BAZEL_BUILD
#include "rpc-client-server/protos/test_rpc.grpc.pb.h"
#else
#include "test_rpc.grpc.pb.h"
#endif

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using testrpc::Operator;
using testrpc::TestgRPC;
using testrpc::SummNote;
using testrpc::OperatorsSummary;
using testrpc::Variables;
using testrpc::Action;


int32_t calculate_operators(const Variables* v) {
    return v->value() + v->value_2();
}

std::string get_operator_name(const Action& action,
                              std::vector<Operator>& oper_list) {
    for (const auto& i : oper_list) {

    }
}

class TestRpcImpl final : public TestgRPC::Service {
public:
	explicit TestRpcImpl(const std::string& db)  {
		testrpc::parse_db(db, &operator_list);
	}
	Status get_result(ServerContext* context, const Variables* var,
			         Operator* unit) override {
//        unit->set_name(unit->name());
        std::cout << "Name: " << unit->name() << '\n';
//        std::cout << "Value: " << var->value() << ' ' << var->value_2() << '\n';
//        unit->mutable_action_()->CopyFrom(*var);
        return Status::OK;
	}

private:
	std::vector<Operator> operator_list;
};

void run_server(const std::string& db_path) {
	std::string server_address("0.0.0.0:50051");
	TestRpcImpl impl(db_path);
	ServerBuilder server_builder;
	server_builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	server_builder.RegisterService(&impl);
	std::unique_ptr<Server> server(server_builder.BuildAndStart());
	std::cout << "Server listening on " << server_address << '\n';
	server->Wait();
}

int main(int argc, char** argv) {

	std::string db = testrpc::get_db_file_content(argc, argv);
	run_server(db);

    return 0;
}
