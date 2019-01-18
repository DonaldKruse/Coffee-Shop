#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <string>
#include <cstdio>

#include "Person.h"
#include "Graph.h"

int main() {
    // make vertices
    Vertex v1 = Vertex(1, true, false, nullptr, "chair");
    Vertex v2 = Vertex(2, false, false, nullptr, "space");
    Vertex v3 = Vertex(3, false, false, nullptr, "space");

    // make AdjacencyLists
    AdjacencyList a1 = std::make_pair(v1, std::vector<Vertex> {v2, v3});
    AdjacencyList a2 = std::make_pair(v2, std::vector<Vertex> {v3, v1});
    AdjacencyList a3 = std::make_pair(v3, std::vector<Vertex> {v1, v2});

    // make graph
    GraphRepresenter g = {a1, a2, a3};

    // make graph obj
    Graph graph1(g);
    // print the graph
    graph1.print_adjacency_lists();
    // find neighbors
    bool v1_2 = graph1.are_neighbors(1, 2);
    if (v1_2)
        printf("v1 and v2 are neighbors\n");
    else
        printf("v1 and v2 are NOT neighbors\n");
    
    // get copy of nodes
    std::vector<Vertex> nodes = graph1.get_nodes();
    // check for more neighbors
    bool v2_3 = graph1.are_neighbors(nodes[1], nodes[2]);
    if (v2_3)
        printf("v2 and v3 are neighbors\n");
    else
        printf("v2 and v3 are NOT neighbors\n");

    // new graph
    // looks like
    //
    //  v1---v2---v3
    //
    a1 = std::make_pair(v1, std::vector<Vertex> {v2});
    a2 = std::make_pair(v2, std::vector<Vertex> {v1,v3});
    a3 = std::make_pair(v3, std::vector<Vertex> {v2});
    g = {a1, a2, a3};
    Graph graph2(g);
    // test fail case for neighbors
    v1_2 = graph2.are_neighbors(1,2);
    if (v1_2)
        printf("v1 and v2 are neighbors\n");
    else
        printf("v1 and v2 are NOT neighbors\n");
    bool v1_3 = graph2.are_neighbors(1,3);
    if (v1_3)
        printf("v1 and v3 are neighbors\n");
    else
        printf("v1 and v3 are NOT neighbors\n");
  
    // test edge case for neighbors
    bool v1_4 = graph2.are_neighbors(1,4);
    if (v1_4)
        printf("v1 and v4 are neighbors\n");
    else
        printf("v1 and v4 are NOT neighbors\n");
 
    return 0;
}