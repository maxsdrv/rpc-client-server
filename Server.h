#pragma once

#include <string>
#include <QObject>

#include "server.grpc.pb.h"
#include "server.grpc.pb.h"

class Server : public QObject {
	Q_OBJECT
public:
	explicit Server(QObject* parent = nullptr);
	~Server() override { qDebug("~Server()"); }
	void run_server(const std::string& db_path);
private:

};

