#pragma once

#include <string>
#include <vector>

namespace testrpc {
class Operator;

std::string get_db_file_content(int argc, char** argv);

void parse_db(const std::string& db, std::vector<Operator>* operator_list);

} //namespace testrpc
