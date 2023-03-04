#pragma once


namespace qtprotobuf::testrpc {

class EchoResponse;

QString get_db_content(int argc, char** argv);
void parse_db(const QString &db, std::vector<EchoResponse> *res_list);

class parser {
public:
	explicit parser(QString db);
	~parser() = default;
	bool try_parse();
private:
	QString _db;
	bool failed = false;
	int current_ = 0;
	bool match(const QString& prefix);
	bool set_failed_and_return_false();
};

} //namespace qtprotobuf::testrpc