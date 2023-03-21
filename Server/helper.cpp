#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <string>
#include <utility>
#include <vector>

#include "helper.h"
#include "rpc_mko.grpc.pb.h"

namespace qtprotobuf::testrpc {

QString get_db_content(int argc, char **argv) {
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

    file.close();

	return line;
}

bool parser::match(const QString &prefix) {
	bool eq = _db.indexOf(current_, prefix.size()) == prefix;
	if (current_ == 0) {
		_db.remove(current_, 1);
		_db.remove(_db.size() - 1, _db.size());
	}
	current_ += prefix.size();
	return eq;
}


parser::parser(QString db) : _db(std::move(db)) {}

bool parser::try_parse(EchoResponse *ptr_res) {
	QJsonParseError parse_error{};
	auto doc = QJsonDocument::fromJson(_db.toUtf8(), &parse_error);
	if (parse_error.error != QJsonParseError::NoError) 
		qWarning() << "Parse error at" << parse_error.offset;

	QJsonObject object = doc.object();
	auto array = object["properties"].toArray();

	QString op_description {};
	QJsonObject obj = array[current_].toObject();

	// ptr_res->mutable_list_messages()->set_name(
	// 	obj["operatorName"].toString().toStdString()
	// 	);
	// ptr_res->mutable_list_messages()->set_command(
	// 	obj["command"].toString().toStdString()
	// 	);

	auto temp = obj.value(QString("description")).isArray(); 
	if (temp) {
		auto ar = obj.value(QString("description")).toArray();
		op_description.append(ar.at(current_).toString());		
	}		
	else 
		op_description.append(obj["description"].toString());

	if (array[++current_].isUndefined()) {
		current_ += _db.size();
	}

	return true;
}
void parse_db(const QString &db, std::vector<EchoResponse> *res_list) {
	res_list->clear();
	QString db_content(db);
	db_content = db_content.simplified();
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

} // namespace qtprotobuf::testrpc
