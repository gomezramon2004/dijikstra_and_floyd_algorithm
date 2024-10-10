#include "floyd_algorithm.hpp"

// Constructor
FloydAlgorithm::FloydAlgorithm(int total_nodes, const std::vector<std::vector<int>>& adjacency_matrix): SIZE(total_nodes), ADJ_MATRIX(adjacency_matrix) {}

// Lambda Function to get the minimum value across all the paths. If the value is less than zero, then convert to INT_MAX
auto get_minimum_value = [](int path_i_j, int path_i_k, int path_k_j) {
    if (path_i_j < 0) path_i_j = INT_MAX;
    if (path_i_k < 0) path_i_k = INT_MAX;
    if (path_k_j < 0) path_k_j = INT_MAX;

    int path_i_k_j = path_i_k + path_k_j;

    return (path_i_j > path_i_k_j && path_i_k != INT_MAX && path_k_j != INT_MAX) ? path_i_k_j : path_i_j;
};

//  Print the results. The shortest path between all pairs of nodes
void FloydAlgorithm::print_result(int total_nodes, const std::vector<std::vector<int>>& adjacency_matrix) const {
  std::cout << "Floyd Algorithm - Shortest path between all pairs of nodes" << ":\n";
  for (int i = 0; i < total_nodes; ++i) {
    for (int j = 0; j < total_nodes; ++j) {
      std::cout << "[" << adjacency_matrix[i][j] << "]";
    }
    std::cout << "\n";
  }
}

// Run the Floyd Algorithm, based on the next reference
// https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
void FloydAlgorithm::run_algorithm() {
  this->output_matrix = new std::vector<std::vector<int>>(this->ADJ_MATRIX);

  for (int k = 0; k < this->SIZE; ++k) {
    for (int i = 0; i < this->SIZE; ++i ) {
      for (int j = 0; j < this->SIZE; ++j) {
        (*this->output_matrix)[i][j] = get_minimum_value((*this->output_matrix)[i][j], (*this->output_matrix)[i][k], (*this->output_matrix)[k][j]);
      }
    }
  }

  this->print_result(this->SIZE, (*this->output_matrix));
  delete this->output_matrix;
  this->output_matrix = nullptr;
}