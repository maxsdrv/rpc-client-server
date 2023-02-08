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
#ifdef BAZEL_BUILD
#include "cmake-build-debug/test_rpc.grpc.pb.h"
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


int calculate_operators(const Variables& v1, int value) {
	return v1.value() + value;
}

std::string get_operator_name(const Variables& var,
						      const std::vector<Operator>& op_list) {

	for (const Operator& o : op_list) {
		if (o.result().value() == var.value()) {
			return o.name();
		}
	}
	return "";
}

class TestRpcImpl final : TestgRPC::Service {
public:
	Status get_summ(ServerContext* context, const Variables* var,
			        Operator* op) override {

	}
private:
	std::vector<Operator> operator_list;
};

int main(int argc, char* argv[]) {

    std::cout << "test";

    return 0;
}
