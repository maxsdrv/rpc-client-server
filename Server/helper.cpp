#include <utility>
#include <vector>
#include <string>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QFile>

#include "helper.h"
#include "rpc_mko.grpc.pb.h"

namespace qtprotobuf::testrpc {

QString get_db_content(int argc, char** argv) {
	std::string db_path;
	std::string arg_str("--db_path");
	if (argc > 1) {
		std::string argv_1 = argv[1];
		size_t start_position = argv_1.find(arg_str);
		if (start_position != std::string::npos) {
			start_position += arg_str.size();
			if (argv_1[start_position] == ' ' || argv_1[start_position] == '=') {
				db_path = argv_1.substr(start_position + 1);
			}
		}
	}
	else {
		db_path = "test_rpc_db.json";
	}

	QFile file(":/test_rpc_db.json");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		std::cerr << "Failed to open " << db_path << std::endl;
		abort();
	}

	QTextStream in(&file);
	QString line;
	while (!file.atEnd()) {
		line = in.readAll();
	}
	return line;
}

parser::parser(QString db) : _db(std::move(db)) {
	QJsonDocument doc = QJsonDocument::fromJson(_db.toUtf8());
	QJsonObject obj = doc.object();
	QVariantMap map = obj.toVariantMap();
	qDebug() << map["name"].toString();
}

void parse_db(const QString& db, std::vector<EchoResponse>* res_list) {
	/* delete spaces */

}

} //namespace qtprotobuf::testrpc


