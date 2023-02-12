#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#ifdef BAZEL_BUILD
#include "grpc-test/protos/test_rpc_grpc.pb.h"
#else
#include "test_rpc.grpc.pb.h"
#endif

#include "JsonParser.h"

namespace testrpc {
std::string get_db_file_content(int argc, char **argv) {
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
	} else {
#ifdef BAZEL_BUILD
		db_path = "grcp-test/test_rpc_db.json"
#else
		db_path = "../test_rpc_db.json";
#endif
	}
	std::ifstream db_file(db_path);
	if (!db_file.is_open()) {
		std::cout << "Failed to open " << db_path << '\n';
		abort();
	}
	std::stringstream db;
	db << db_file.rdbuf();
	return db.str();
}

class Parser {
public:
	explicit Parser(std::string db) : db_(std::move(db)) {
		db_.erase(std::remove_if(db_.begin(), db_.end(), isspace), db_.end());
		if (!match("[")) {
			set_failed_and_return_false();
		}
	}
	bool finished() { return current_ >= db_.size(); }
	bool try_parse_one(Operator* i) {
		if (failed_ || finished() || !match("{")) {
			return set_failed_and_return_false();
		}
		if (!match(values_) || !match("{") || !match(first_val)) {
			return set_failed_and_return_false();
		}
		long temp = 0;
		read_long(&temp);
		i->mutable_items()->set_value(static_cast<int>(temp));
		if (!match(",") || !match(second_val)) {
			return set_failed_and_return_false();
		}
		read_long(&temp);
		i->mutable_items()->set_value_2(static_cast<int>(temp));
		if (!match("},") || !match(name_) || !match("\"")) {
			return set_failed_and_return_false();
		}
		size_t name_start = current_;
		while (current_ != db_.size() && db_[current_ ++] != '"') {}
		if (current_ == db_.size()) {
			return set_failed_and_return_false();
		}
		i->set_name(db_.substr(name_start, current_ - name_start - 1));
		if (!match("},")) {
			if (db_[current_ - 1] == ']' && current_ == db_.size()) {
				return true;
			}
			return set_failed_and_return_false();
		}
		return true;
	}


private:
	bool match(const std::string &prefix) {
		bool eq = db_.substr(current_, prefix.size()) == prefix;
		current_ += prefix.size();
		return eq;
	}
	bool set_failed_and_return_false() {
		failed_ = true;
		return false;
	}
	void read_long(long* l) {
		size_t start = current_;
		while (current_ != db_.size() && db_[current_] != ',' && db_[current_] != '}') {
			++current_;
		}
		// It will throw exception if fails.
		*l = std::stol(db_.substr(start, current_ - start));
	}

	bool failed_{false};
	std::string db_;
	size_t current_ {0};
	const std::string values_ {"\"values\":"};
	const std::string first_val {"\"first\":"};
	const std::string second_val {"\"second\":"};
	const std::string name_ {"\"name\":"};
};

void parse_db(const std::string& db, std::vector<Operator>* operator_list) {
	operator_list->clear();
	std::string db_content(db);
	db_content.erase(
		std::remove_if(db_content.begin(), db_content.end(), isspace),
		db_content.end()
		);

	Parser parser(db_content);
	Operator op;
	while (!parser.finished()) {
		operator_list->push_back(Operator());
		if (!parser.try_parse_one(&operator_list->back())) {
			std::cout << "Error parsing the db file";
			operator_list->clear();
			break;
		}
	}
	std::cout << "DB parsed, loaded " << operator_list->size() << " operators.\n";

}

} // namespace testrpc









