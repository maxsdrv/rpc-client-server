#pragma once


namespace qtprotobuf::testrpc {

class EchoResponse;

QString get_db_content(int argc, char** argv);
void parse_db(const QString &db, std::vector<EchoResponse> *res_list);

class parser {
public:
	explicit parser(QString db);
	~parser() = default;
private:
	QString _db;
};

} //namespace qtprotobuf::testrpc