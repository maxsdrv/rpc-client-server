#include "ServerMKO.h"


ServerMKO::ServerMKO(const std::string& db, QObject *parent) : QTcpServer(parent) {
  testrpc::parse_db(db, &list_operators);
}

int main(int argc, char **argv) {
  std::string db = testrpc::get_db_file_content(argc, argv);
  ServerMKO s(db);

  return 0;
}
