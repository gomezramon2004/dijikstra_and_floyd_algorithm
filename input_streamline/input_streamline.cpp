#include "input_streamline.hpp"

// Constructor
InputStreamline::InputStreamline(const std::string& file_dir): file(file_dir), line("") {
  if (!this->file.is_open()) {
    throw std::runtime_error("Error: File can't be opened");
  }
}

// Lambda function to check if certain element is a number or not
auto check_if_number = [](const std::string& element) {
  const int is_negative = (element[0] ? 1 : 0);
  const int total_digits = std::count_if( element.begin() + is_negative, element.end(), []( char c ) { return std::isdigit( c ); } );
  return total_digits == element.size() - is_negative;
};

// Helper function to get the matrix nodes with error handling
std::vector<std::vector<int>> InputStreamline::get_matrix_nodes(int total_nodes) {
  std::vector<std::vector<int>> matrix(total_nodes, std::vector<int>(total_nodes));

  for (int i = 0; i < total_nodes; ++i) {
    if (!std::getline(this->file, this->line)) {
      throw std::runtime_error("Error: Line #" + std::to_string(i + 2) + " can't be found");
    }

    std::istringstream streamline(this->line);

    for (int j = 0; j < total_nodes; ++j) {
      streamline >> this->element_matrix;

      if (!check_if_number(this->element_matrix)) {
        throw std::runtime_error("Error: Can't be parsed the matrix element at [" + std::to_string(i) + "][" + std::to_string(j) +"]");
      }
      
      matrix[i][j] = std::stoi(this->element_matrix);
    }
  }

  return matrix;
}

// Get the input from the file text (total nodes and the adjacency matrix) with error handling
std::pair<int, std::vector<std::vector<int>>> InputStreamline::get_input() {
  if (!std::getline(this->file, this->line)) {
    throw std::runtime_error("Error: Line #1 (total nodes) can't be found");
  }

  int total_nodes{0};

  try {
    total_nodes = std::stoi(this->line);
  } catch (const std::exception& e) {
    throw std::runtime_error("Error: Can't be parsed the total number of nodes");
  }

  return std::make_pair(total_nodes, this->get_matrix_nodes(total_nodes));
}