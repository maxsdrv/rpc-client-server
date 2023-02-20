#include "Server.h"

Server::Server(QObject* parent) : QObject(parent) {

}

void Server::run_server(const std::string& db_path) {
	std::string server_address("0.0.0.0:65000");


}