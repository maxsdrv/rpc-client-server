#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <numeric>
#include <optional>
#include <string>

#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#ifdef BAZEL_BUILD
#include "rpc-client-server/protos/test_rpc.grpc.pb.h"
#else
#include "test_rpc.grpc.pb.h"
#endif

#include "JsonParser.h"
#include "profile.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using testrpc::Action;
using testrpc::Operator;
using testrpc::OperatorsSummary;
using testrpc::SummNote;
using testrpc::TestgRPC;
using testrpc::Variables;

int32_t calculate_operators(const Variables *v) {
  return v->value() + v->value_2();
}

std::optional<Operator> get_operator_name(Operator* unit,
                                          std::vector<Operator> &oper_list) {

  LOG_DURATION("find_if");
  
    

  return {};
}

class TestRpcImpl final : public TestgRPC::Service {
public:
  explicit TestRpcImpl(const std::string &db) {
    testrpc::parse_db(db, &operator_list);
  }
  Status get_result(ServerContext *context, const Variables *var,
                    Operator *unit) override {

    //TODO

    return Status::OK;
  }

private:
  std::vector<Operator> operator_list;
};

void run_server(const std::string &db_path) {
  std::string server_address("0.0.0.0:50051");
  TestRpcImpl impl(db_path);
  ServerBuilder server_builder;
  server_builder.AddListeningPort(server_address,
                                  grpc::InsecureServerCredentials());
  server_builder.RegisterService(&impl);
  std::unique_ptr<Server> server(server_builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << '\n';
  server->Wait();
}

int main(int argc, char **argv) {

  std::string db = testrpc::get_db_file_content(argc, argv);
  run_server(db);

  return 0;
}
