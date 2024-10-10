#include "dijkstra_algorithm/dijkstra_algorithm.hpp"
#include "input_streamline/input_streamline.hpp"

int main() {
  try {
    InputStreamline input_streamline("in.txt");
    std::pair<int, std::vector<std::vector<int>>> input = input_streamline.get_input();
    const auto& [total_nodes, matrix_adj] = input;

    DijkstraAlgorithm dijkstra_algorithm(total_nodes, matrix_adj);
    for (int i = 0; i < total_nodes; i++) {
      dijkstra_algorithm.run_algorithm(i);
    }

    
  } catch (const std::exception& e) {
    throw std::runtime_error("Error: " + std::string(e.what()));
    return 1;
  }

  return 0;
}