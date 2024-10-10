#pragma once

#include <iostream>
#include <set>

struct MatrixPositions { 
  int path_i_j;
  int path_i_k;
  int path_j_k;
  MatrixPositions(int ij, int ik, int jk) : path_i_j(ij), path_i_k(ik), path_j_k(jk) {}
}; 

class FloydAlgorithm {
  private:
    const int SIZE;
    const std::vector<std::vector<int>>& ADJ_MATRIX;
    std::vector<std::vector<int>>* output_matrix;
    void print_result(int total_nodes, const std::vector<std::vector<int>>& adjacency_matrix) const;
  public:
    FloydAlgorithm(int total_nodes, const std::vector<std::vector<int>>& adjacency_matrix);
    void run_algorithm();
};