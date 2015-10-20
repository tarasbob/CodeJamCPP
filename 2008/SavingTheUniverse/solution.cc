#include <string>
#include <vector>
#include <iostream>
#include <set>

int solve(const std::vector<std::string> &engines, const std::vector<std::string> &queries) {

  std::set<std::string> all_engines(engines.begin(), engines.end());
  std::set<std::string> available(all_engines);
  int num_switches = 0;
  for (std::vector<std::string>::const_iterator it = queries.begin(); it != queries.end(); it++) {
    available.erase(*it);
    if (available.size() == 0) {
      available = all_engines;
      available.erase(*it);
      num_switches++;
    }
  }
  return num_switches;
}


int main(int argc, char* argv[]) {
  int num_cases;
  std::cin >> num_cases;
  for (int case_num = 1; case_num <= num_cases; case_num++) {
    int num_engines;
    std::cin >> num_engines;
    std::vector<std::string> engines;
    std::string line;
    std::getline(std::cin, line);
    for (int i = 0; i < num_engines; i++) {
      std::getline(std::cin, line);
      engines.push_back(line);
    }
    int num_queries;
    std::cin >> num_queries;
    std::vector<std::string> queries;
    std::getline(std::cin, line);
    for (int i = 0; i < num_queries; i++) {
      std::getline(std::cin, line);
      queries.push_back(line);
    }
    std::cout << "Case #" << case_num << ": " << solve(engines, queries) << std::endl;
  }
}
