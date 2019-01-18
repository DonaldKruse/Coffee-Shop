#ifndef NAVIGATOR_H_
#define NAVIGATOR_H_

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

    // Returns a list of vertices representing the shortest path from start to finish.
    std::list<vertex> search(vertex *start, vertex *finish);
}

#endif  // NAVIGATOR_H_
