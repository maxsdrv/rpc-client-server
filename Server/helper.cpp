#include <utility>
#include <vector>
#include <string>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QFile>
#include <QJsonArray>

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

bool parser::match(const QString& prefix) {
	bool eq = _db.indexOf(current_, prefix.size()) == prefix;
	if (current_ == 0) {
		_db.remove(current_, 1);
		_db.remove(_db.size() - 1, _db.size());
	}
	current_ += prefix.size();
	return eq;
}
bool parser::set_failed_and_return_false() {
	failed = true;
	return false;
}
parser::parser(QString db) : _db(std::move(db)) {
	/* remove "[" "]"  */
	/*if (!match("[")) {
		set_failed_and_return_false();
	}*/
}
bool parser::try_parse(EchoResponse* ptr_res) {
	QJsonParseError parse_error{};
	QJsonDocument doc = QJsonDocument::fromJson(_db.toUtf8(), &parse_error);
	if (parse_error.error != QJsonParseError::NoError) {
		qWarning() << "Parse error at" << parse_error.offset;
	}
	QJsonObject object = doc.object();
	QVariantMap map = object.toVariantMap();
	qDebug() << map["operatorName"].toString();
	qDebug() << map["command"].toString();
	QJsonValue value = object.value("description");
	QJsonArray array = value.toArray();
	for (const auto& a : array) {
		qDebug() << a.toString();
	}

}
void parse_db(const QString& db, std::vector<EchoResponse>* res_list) {
	res_list->clear();
	QString db_content(db);
	db_content = db_content.simplified();
	db_content.replace(" ", "");
	parser parser(std::move(db_content));
	EchoResponse response;
	while (!parser.is_finished()) {
		res_list->emplace_back(EchoResponse());
		if (!parser.try_parse(&res_list->back())) {
			qDebug() << "Error parsing the db file";
			res_list->clear();
			break;
		}
	}
	qDebug() << "DB parsed, loaded " << res_list->size() << " operators.";
}

} //namespace qtprotobuf::testrpc


