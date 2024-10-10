#pragma once

#include <iostream>

class FloydAlgorithm {
  private:
    const int& SIZE;
    const std::vector<std::vector<int>>& ADJ_MATRIX;
    std::vector<std::vector<int>>* output_matrix;
    void print_result(int total_nodes, const std::vector<std::vector<int>>& adjacency_matrix);
  public:
    FloydAlgorithm(int total_nodes, const std::vector<std::vector<int>>& adjacency_matrix);
    void run_algorithm();
};