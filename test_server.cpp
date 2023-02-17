#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <numeric>
#include <optional>
#include <string>
#include <memory>

#include <QTcpServer>
#include <QDebug>

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
using testrpc::Operator;
using testrpc::OperatorsSummary;
using testrpc::SummNote;
using testrpc::TestgRPC;
using testrpc::Variables;
using testrpc::ListOperators;
using testrpc::Response;
using google::protobuf::Empty;


Response calculate_operators(const Variables *v) {
  Response response;
  response.set_result_(v->value() + v->value_2());
  return response;
}

std::optional<Operator> get_created_operator(Operator* unit,
                                          std::vector<Operator> &oper_list) {

  LOG_DURATION("Free function get_operator_name()");

  unit->set_name(oper_list.back().name());
  auto res_calculate = calculate_operators(&oper_list.back().items());
  unit->mutable_response_()->CopyFrom(res_calculate);
	return *unit;
}

class TestRpcImpl : public QTcpServer {

public:

  explicit TestRpcImpl(const std::string &db) {
    testrpc::parse_db(db, &operator_list);
  }
  Status get_result(ServerContext *context, const Empty* empty,
                    Operator *unit){

    //TODO
    auto ptr_unit = get_created_operator(unit, operator_list);
    if (ptr_unit.has_value()) {
      std::cout << "Unit has value!!!\n";
    }

    return Status::OK;
  }
  Status get_json(ServerContext* context, const Empty* empty, ListOperators* opr) {
   
    return Status::OK;
  }

private:
  std::vector<Operator> operator_list;
};

void run_server(const std::string &db_path) {
  std::string server_address("0.0.0.0:50051");
  TestRpcImpl impl(db_path);
  std::cout << "Server listening on " << server_address << '\n';
}

int main(int argc, char **argv) {

  std::string db = testrpc::get_db_file_content(argc, argv);
  run_server(db);

  return 0;
}
