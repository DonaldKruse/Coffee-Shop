#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <list>
#include <string>
#include <cstdio>

#include "Person.h"
#include "Graph.h"
#include "Navigator.h"

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

    // new graph
    // looks like
    //
    //  v1---v2---v3
    //
    a1 = std::make_pair(v1, std::vector<Vertex> {v2});
    a2 = std::make_pair(v2, std::vector<Vertex> {v1,v3});
    a3 = std::make_pair(v3, std::vector<Vertex> {v2});
    g = {a1, a2, a3};
    Navigator nav1(g);

    std::list<unsigned int> path;
    path = nav1.search(1, 3);

    std::cout << "Path: ";
    for (auto& v : path) {
        std::cout << v << ",";
    }
    std::cout << std::endl;

    return 0;
}
