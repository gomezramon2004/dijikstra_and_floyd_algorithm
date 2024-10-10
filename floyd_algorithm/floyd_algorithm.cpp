#include "floyd_algorithm.hpp"

// Constructor
FloydAlgorithm::FloydAlgorithm(int total_nodes, const std::vector<std::vector<int>>& adjacency_matrix): SIZE(total_nodes), ADJ_MATRIX(adjacency_matrix) {}

//  Print the results. The shortest path between all pairs of nodes
void FloydAlgorithm::print_result(int total_nodes, const std::vector<std::vector<int>>& adjacency_matrix) {
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
  this->output_matrix = new std::vector<std::vector<int>>(this->SIZE, std::vector<int>(this->SIZE, 0));

  for (int k = 0; k < this->SIZE; ++k) {
    for (int i = 0; i < this->SIZE; ++i ) {
      for (int j = 0; j < this->SIZE; ++j) {
        (*this->output_matrix)[i][j] = (*this->output_matrix)[i][j] || ((*this->output_matrix)[i][k] + (*this->output_matrix)[k][j]);
      }
    }
  }

  this->print_result(this->SIZE, (*this->output_matrix));
  delete this->output_matrix;
  this->output_matrix = nullptr;
}