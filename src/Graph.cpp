#include "Graph.h"
#include <map>
#include <unordered_map>
#include <string>


// -- Constructor --
//
Graph::Graph(GraphRepresenter graph) {
    _graph = graph;

    // get number of nodes
    _num_nodes = _graph.size();

    // get number of chairs, occupied chairs, and persons
    unsigned int numchairs   = 0;
    unsigned int numoccupied = 0;
    unsigned int numpersons  = 0;
    for ( auto it = _graph.begin(); it != _graph.begin(); it++ ) {
        auto fst = it->first;

        if ( fst.is_chair )
            numchairs++;

        if ( fst.is_occupied )
            numoccupied++;

        if ( fst.person == nullptr )
            numpersons++;
    }
    _num_chairs = numchairs;
    _num_chairs_occupied = numoccupied;
    _num_persons = numpersons;
}

Graph::~Graph() {}
