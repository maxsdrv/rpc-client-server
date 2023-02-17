#pragma once

#include <vector>
#include <QDebug>
#include <QTcpServer>


#include "JsonParser.h"
#include "profile.h"
#include "test_rpc.pb.h"
#include <grpc/grpc.h>
#include <test_rpc.grpc.pb.h>

using google::protobuf::Empty;
using grpc::Status;
using testrpc::Operator;
using testrpc::Response;
using testrpc::TestgRPC;
using testrpc::Variables;

class ServerMKO final : public QTcpServer {
  Q_OBJECT

public:
  explicit ServerMKO(const std::string &db, QObject *parent = nullptr);
  ~ServerMKO() override { qDebug() << "~ServerMKO()"; }

private:
  std::vector<Operator> list_operators;
};
