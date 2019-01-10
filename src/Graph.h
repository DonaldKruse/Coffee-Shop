#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <map>

struct vertex {
    int label;        // unique ID for the node
    bool is_chair;    // is this node a chair
    bool is_occupied; // is the chair occupied
    Person * person;  // if occupied, the person (or nemo) in the chair
    std::string name; // optional name for the node

    // constructor
    vertex(int vlabel,
           bool vis_chair,
           bool vis_occupied,
           Person * vperson,
           std::string vname) :

           label(vlabel),
           is_chair(vis_chair),
           is_occupied(vis_occupied),
           person(vperson),
           name(vname)
           {}
};

// adjacency list
typedef adjacency_list std::map< vertex, std::vector<vertex> >;

class Graph {
    private:
        //node_and_verts defined above
        adjacency_list al;
        
        // basic info for size and other metrics
        unsigned int num_nodes;
        unsigned int num_chairs;
        unsigned int num_chairs_occupied;
        unsigned int num_persons; // number of Person objs graph obj points to
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

        // TODO methods for intersection and unions of graphs

        // TODO destructor
}
