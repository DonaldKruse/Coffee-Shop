#include "Graph.h"
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

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


unsigned int Graph::get_num_nodes() {
    return _num_nodes;
}


unsigned int Graph::get_num_chairs() {
    return _num_chairs;
}


unsigned int Graph::get_num_chairs_occupied() {
    return _num_chairs_occupied;
}


unsigned int Graph::get_num_persons() {
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


void Graph::print_adjacency_lists() {
    for (auto p_node = _graph.begin(); p_node != _graph.end(); p_node++) {
        printf("[ %u | ", p_node->first.label);
        for (auto it = p_node->second.begin(); it != p_node->second.end(); it++) {
            printf("%u ", it->label);
        }
        printf(" ]\n");
    }
}



bool Graph::are_neighbors(unsigned int node1, unsigned int node2) {
    // unary predicates for finding correct adjacency list
    // needed in std::find_if
    auto find_node1 = [&node1] (AdjacencyList & adjlist)
                      {
                          return node1 == adjlist.first.label;
                      };
    auto find_node2 = [&node2] (AdjacencyList & adjlist)
                      {
                          return node2 == adjlist.first.label;
                      };

    // get correct pointers to adjacency list
    auto p_adjlist1 = std::find_if(_graph.begin(), _graph.end(), find_node1);
    auto p_adjlist2 = std::find_if(_graph.begin(), _graph.end(), find_node2);
    
    // if either pointer points to end, impossible neighbors
    if (p_adjlist1 == _graph.end() || p_adjlist2 == _graph.end()) {
        return false;
    }

    // look for nodes in the adjacency lists
    auto neighbornode1 = std::find(p_adjlist1->second.begin(), p_adjlist1->second.end(), p_adjlist2->first.label);
    auto neighbornode2 = std::find(p_adjlist2->second.begin(), p_adjlist2->second.end(), p_adjlist1->first.label);

    // if neither are end pointers, then they are neighbors
    if (neighbornode1 != p_adjlist1->second.end() && neighbornode2 != p_adjlist2->second.end()) {
        return true;
    } else {
        return false;
    }
}  


bool Graph::are_neighbors(Vertex vertex1, Vertex vertex2) {
    return are_neighbors(vertex1.label, vertex2.label);
}   



Graph::~Graph() {}
