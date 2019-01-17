#ifndef NAVIGATOR_H
#define NAVIGATOR_H

// File: navigator.h
// Purpose: Class implementing Dijkstra's Algorithm for finding the shortest path in a graph.

#include <list>
#include "graph.h"


class Navigator : Graph {
    private:
    public:

    // Construct Navigator with empty Graph
    Navigator(); 

    // TODO -- Create construct that builds a fully populated graph.
    //Navigator(<<list of vertices>>, <<list of edges>>);

    // Destructor
    ~Navigator();

    // Returns a list of vertices representing the shortest path from X to Y.
    std::list<vertex> search(vertex *X, vertex *Y);
}
