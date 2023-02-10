#include <iostream>
#include <chrono>
#include <memory>
#include <random>
#include <string>
#include <thread>

#include "JsonParser.h"

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "test_rpc.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;
using testrpc::Operator;
using testrpc::Variables;
using testrpc::TestgRPC;
using testrpc::SummNote;
using testrpc::OperatorsSummary;

class TestRpcClient {
public:
	TestRpcClient(std::shared_ptr<Channel> channel, const std::string& db) :
				  stub_(TestgRPC::NewStub(channel)) {
		testrpc::parse_db(db, &operator_list);
	}
private:
	bool get_one_operator(const Variables& var, Operator* op) {
		ClientContext context;
		Status status = stub_->get_summ(&context, var, op);
		if (!status.ok()) {
			std::cout << "get_summ rpc failed. " << std::endl;
			return false;
		}
		if (!op->has_result()) {
			std::cout << "Server return incomplete operator. " << std::endl;
			return false;
		}
		else {
			std::cout << "Found operator called " << op->name() << " at "
					   << op->result().value() << ", "
					   << op->result().value_2() << std::endl;
		}

	}
	std::unique_ptr<TestgRPC::Stub> stub_;
	std::vector<Operator> operator_list;
};


int main(int argc, char* argv[]) {
	std::string db = testrpc::get_db_file_content(argc, argv);
	TestRpcClient client(grpc::CreateChannel("localhost:50051",
											 grpc::InsecureChannelCredentials()),
						 db);

	std::cout << "-------------------- GetFeature ----------------" << std::endl;

	return 0;
}