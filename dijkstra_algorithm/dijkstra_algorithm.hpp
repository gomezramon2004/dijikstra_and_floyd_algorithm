#pragma once

#include <iostream>

struct DistanceInfo {
  int distance;
  bool finalized;
  DistanceInfo(int dist, bool is_finalized) : distance(dist), finalized(is_finalized) {}
};

class DijkstraAlgorithm {
  private:
    const int SIZE;
    const std::vector<std::vector<int>> ADJ_MATRIX;
    std::vector<DistanceInfo>* distances;
    int get_min_distance_index(const std::vector<DistanceInfo>& distances);
    void print_result(const int& index_source, const std::vector<DistanceInfo>& distances);
  public:
    DijkstraAlgorithm(const int& total_nodes, const std::vector<std::vector<int>>& adjacency_matrix);
    void run_algorithm(const int& index_source);
};