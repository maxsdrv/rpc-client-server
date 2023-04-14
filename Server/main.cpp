#include <QDebug>
#include <functional>
#include <csignal>

#include "Server.h"
#include "helper.h"


void run_server(const QString& db_path) {
	std::string server_address("0.0.0.0:65000");
	std::cout << "Test server db_path: " << std::endl;
	MKOServer service(db_path);
	ServerBuilder builder;
	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	builder.RegisterService(&service);
	std::unique_ptr<Server> server(builder.BuildAndStart());
	std::cout << "Server listening on " << server_address << std::endl;

	server->Wait();
}

int main(int argc, char** argv) {
	qDebug("Server test");
	QString db = qtprotobuf::testrpc::get_db_content(argc, argv);
	run_server(db);

	return 0;
}
