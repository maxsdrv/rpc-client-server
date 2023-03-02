#include "Server.h"
#include "helper.h"

MKOServer::MKOServer(const QString& db) {
	qtprotobuf::testrpc::parse_db(db, &_res_list);
}


