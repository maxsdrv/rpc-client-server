#include <chrono>
#include <google/protobuf/empty.pb.h>
#include <iostream>
#include <memory>
#include <random>
#include <string>
//#include <thread>
#include <string_view>

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
using testrpc::OperatorsSummary;
using testrpc::SummNote;
using testrpc::TestgRPC;
using testrpc::Variables;
using testrpc::ListOperators;
using google::protobuf::Empty;

Variables make_var(int32_t v1, int32_t v2) {
  Variables v;
  v.set_value(v1);
  v.set_value_2(v2);
  return v;
}


class TestRpcClient {
public:
  TestRpcClient(std::shared_ptr<Channel> channel, const std::string &db)
      : stub_(TestgRPC::NewStub(channel)) {
    testrpc::parse_db(db, &operator_list);
  }
  void get_operator() {
    Variables variables;
    Operator list_op;
    variables = make_var(1000, 5000);
    get_one_operator(variables, &list_op);
  }

private:
  bool get_one_operator(const Variables &var, Operator *list_op) {
    ClientContext context;

    Status status = stub_->get_result(&context, Empty::default_instance(), list_op);
    if (!status.ok()) {
      std::cout << "get_result rpc failed. " << std::endl;
      return false;
    }
    if (!list_op->has_response_()) {
      std::cout << "Server return incomplete operator. " << std::endl;
      return false;
    } else {
      std::cout << "Found operator called " << list_op->name() << " at "
                << list_op->response_().result_() << std::endl;
    }

    return true;
  }
  std::unique_ptr<TestgRPC::Stub> stub_;
  std::vector<Operator> operator_list;
};

int main(int argc, char *argv[]) {
  std::string db = testrpc::get_db_file_content(argc, argv);
  TestRpcClient client(grpc::CreateChannel("localhost:50051",
                                           grpc::InsecureChannelCredentials()),
                       db);

  std::cout << "-------------------- GetFeature ----------------" << std::endl;
  client.get_operator();

  return 0;
}
