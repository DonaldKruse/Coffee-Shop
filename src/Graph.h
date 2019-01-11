#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <unordered_map>
#include <map>

/* a vertex that is used in the Graph class
 *
 * Should only contain public data and no
 * information about neighbors, connections, etc.
 */
struct vertex {
    unsigned int label;   // unique ID for the node -- starts from zero
    bool is_chair;        // is this node a chair
    bool is_occupied;     // is the chair occupied
    Person * person;      // if occupied, the person (or nemo) in the chair
    std::string name;     // optional name for the node

    // constructor
    vertex(unsigned int vlabel,
           bool vis_chair,
           bool vis_occupied,
           Person * vperson,
           std::string vname) :

           label (vlabel),
           is_chair (vis_chair),
           is_occupied (vis_occupied),
           person (vperson),
           name (vname)
           {}
};

// adjacency list for a single vertex 
typedef adjacency_list std::unordered_map< vertex, std::vector<vertex> >;

// This is the actual representation of the graph -- a list of adjacency lists.
// Order somewhat matters. May change later.
typedef graph_representer std::map< vertex, adjacency_list >;


// TODO
// Documentation on this class
class Graph {
    private:
        graph_representer _graph;
        
        // basic info for size and other metrics
        unsigned int _num_nodes;
        unsigned int _num_chairs;
        unsigned int _num_chairs_occupied;
        unsigned int _num_persons; // number of Person objs that exists in the  graph
        
        // TODO
        // union and intersection methods (if needed) should be private
        
        // TODO
        // update on number of nodes, chairs, persons, etc...
        

    public:
        // general constructors
        //
        Graph();
        Graph(adjacency_list & adjlist) : _adjlist(adjlist) {};

        // getters and setters for vertices, edges
        //
        adjacency_list * get_adjlist ();             // dangerous
        void get_num_nodes ();
        void get_num_chairs ();
        void get_num_chairs_occupied ();
        void get_num_persons ();

        // TODO -- check to make sure this is an adequate prototype
        /* add_adjlist_to_graph
         *
         * input new_adjlists: an graph_representer that will be merged
         *                    with this Graph's _graph
         *
         * output: void  
         *
         * exceptions: TODO
         *
         * Notes: This method does not check for any correctness of
         *        of the graph, but copies the contents of 
         *        new_adjlist to this._graph then performs
         *        and update on the number of nodes, persons, etc...
         *
         */
        void add_adjlist_to_graph(graph_representer new_adjlists);

        
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

#endif // GRAPH_H
