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


void Graph::get_num_nodes() {
    return _num_nodes;
}


void Graph::get_num_chairs() {
    return _num_chairs;
}


void Graph::get_num_chairs_occupied() {
    return _num_chairs_occupied;
}


void Graph:get_num_persons() {
    return _num_persons;
}


std::vector<Vertex> Graph::get_nodes() {
    std::vector<Vertex> nodes;

    for (auto it = _graph.begin(); it != _graph.end(); it++) {
        nodes.push_back(it->first);
    }
   
    return nodes;
}


GraphRepresenter Graph::get_graph_representer() {
    return _graph;
}


//bool Graph::are_neighbors(Vertex v1, Vertex v2) {
//}
    
Graph::~Graph() {}
