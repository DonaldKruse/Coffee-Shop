#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <map>

struct vertex {
    int label;
    bool is_chair;
    bool is_chair_occupied;
    Person * person; // person (or nemo) in the chair
    std::string vert_name;
};

// node and list of verts
typedef node_and_verts std::map< int, std::vector<vertex> >;

class Graph {
    private:
        // TODO
        // need: node_and_verts (above)
        // need: basic info for size and other metrics

    public:
        // TODO
        // general constructors
        // getters and setters for nodes, edges
        
        // TODO ops on single given node in graph
        //    list of neighbors
        //    what kind of node

        // TODO test for adjacency between two nodes
    
        // TODO insert and delete for nodes and edges
     
        // TODO determine how and when to use a sparse matrix/data struct
        //      for example std::unordered_map has average constant-time complexity
        //      for lookup, insert, etc...


        // TODO destructor
}
