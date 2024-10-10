#pragma once

#include <fstream>
#include <sstream>

class InputStreamline {
  private:
    std::ifstream file;
    std::string line;
    std::string element_matrix;
    std::vector<std::vector<int>> get_matrix_nodes(int total_nodes);
  public:
    InputStreamline(const std::string& file_dir);
    std::pair<int, std::vector<std::vector<int>>> get_input();
};