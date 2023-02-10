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
#include "grpc-test/protos/test_rpc.grpc.pb.h"
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


const Operator& calculate_operators(const Operator* op) {
	 op->result().value() + op->result().value_2();
	 return *op;
}

std::string get_operator_name(const Variables& var,
						      const std::vector<Operator>& op_list) {

	for (const Operator& o : op_list) {
		if (o.result().value() == var.value() &&
			o.result().value_2() == var.value_2()) {
			return o.name();
		}
	}
	return "";
}

class TestRpcImpl final : public TestgRPC::Service {
public:
	explicit TestRpcImpl(const std::string& db)  {
		testrpc::parse_db(db, &operator_list);
	}
	Status get_result(ServerContext* context, const Variables* var,
			        Addition* add) override {
		add->set_name(get_operator_name(*var, operator_list));
		add->mutable_result()->CopyFrom(*var);

		return Status::OK;
	}
	Status list_operators(ServerContext* context,
						  const Operator* v,
						  ServerWriter<Operator>* writer) override {
		for (auto& o : operator_list) {
			v = &calculate_operators(&o);
			writer->Write(*v);
		}
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
