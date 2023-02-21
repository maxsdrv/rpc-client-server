#include "Server.h"

MKOServer::MKOServer() {

}

void MKOServer::run_server(const std::string& db_path) {
	std::string server_address("0.0.0.0:65000");
	std::cout << "Test server db_path: " << db_path << std::endl;
	MKOServer service;
	ServerBuilder builder;
	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	builder.RegisterService(&service);
	std::unique_ptr<Server> server(builder.BuildAndStart());
	std::cout << "Server listening on " << server_address << std::endl;
	server->Wait();
}