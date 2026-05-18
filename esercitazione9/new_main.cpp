#include <iostream>
#include "classi.hpp"

int main() {
    grafo_non_direzionato<int> G;
    G.add_edge(arco_non_direzionato<int>(1,2));
    G.add_edge(arco_non_direzionato<int>(1,3));
    G.add_edge(arco_non_direzionato<int>(1,4));
    G.add_edge(arco_non_direzionato<int>(1,6));
    G.add_edge(arco_non_direzionato<int>(2,4));
    G.add_edge(arco_non_direzionato<int>(2,5));
    G.add_edge(arco_non_direzionato<int>(2,7));
    G.add_edge(arco_non_direzionato<int>(3,6));
    G.add_edge(arco_non_direzionato<int>(4,6));
    G.add_edge(arco_non_direzionato<int>(4,7));
    G.add_edge(arco_non_direzionato<int>(5,7));
    G.add_edge(arco_non_direzionato<int>(6,7));
    G.add_edge(arco_non_direzionato<int>(6,8));
    G.add_edge(arco_non_direzionato<int>(7,9));
    G.add_edge(arco_non_direzionato<int>(8,9));
    //bfs
    fifo<int> coda;
    auto bfsG = graph_visit(G, 1, coda);
    std::cout << "BFS\n";
    for (const auto& arco : bfsG.all_edges()) {
        std::cout << arco << " ";
    }
    //dfs
    lifo<int> stack;
    auto dfsG = graph_visit(G, 1, stack);
    std::cout << "\nDFS\n";
    for (const auto& arco : dfsG.all_edges()) {
        std::cout << arco << " ";
    }
    //dfs_ricorsiva
    auto copiaG = G; 
    auto dfsRicG = recursive_dfs(copiaG, 1);
    // auto dfsRicG = recursive_dfs(G, 1);
    std::cout << "\nDFS ricorsiva\n";
    for (const auto& arco : dfsRicG.all_edges()) {
        std::cout << arco << " ";
    }
    //Dijkstra
    auto dijG = dijkstra(G, 1);
    std::cout << "\nDijkstra\n";
    for (const auto& arco : dijG.all_edges()) {
        std::cout << arco << " ";
    }
    return 0;
}