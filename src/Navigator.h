#ifndef NAVIGATOR_H_
#define NAVIGATOR_H_

// File: navigator.h
// Purpose: Class implementing Dijkstra's Algorithm for finding the shortest path in a graph.

#include <list>
#include "Graph.h"


class Navigator {
    private:
        GraphRepresenter _my_Map;

    public:

    // Construct Navigator with initial Graph
    explicit Navigator(GraphRepresenter graph); 

    // Destructor
    ~Navigator();

    // Returns a list of vertices representing the shortest path from X to Y.
    std::list<unsigned int> search(unsigned int start, unsigned int finish);
};
#endif // NAVIGATOR_H_
        
