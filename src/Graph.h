#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>
#include <vector>
#include <utility>  // std::pair
#include "Person.h"


/* A Vertex that is used in the Graph class
 *
 * Should only contain public data and no
 * information about neighbors, connections, etc.
 */
struct Vertex {
    unsigned int label;   // unique ID for the node -- starts from zero
    bool is_chair;        // is this node a chair
    bool is_occupied;     // is the chair occupied
    Person * person;      // if occupied, the person (or nemo) in the chair
    std::string name;     // optional name for the node


    // constructor
    Vertex(unsigned int vlabel,
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


    // -- operator overloading --


    //   std::sort
    bool operator<(const Vertex &v) const {
        return (label < v.label);
    }

    //   std::find
    bool operator==(const Vertex &v) const {
        return (label == v.label);
    }
    bool operator==(const unsigned int l) const {
        return (label == l);
    }
};


// adjacency list for a single Vertex
typedef std::pair< Vertex, std::vector<Vertex> > AdjacencyList;


// This is the actual representation of the graph -- a list of adjacency lists.
//
// This may need to be changed to an unordered map for efficiency later.
typedef std::vector< AdjacencyList > GraphRepresenter;


/*
 *  Graph provides the basic structure and data for
 *  a graph object.
 */
class Graph {
    private:
        GraphRepresenter _graph;

        // basic info for size and other metrics
        unsigned int _num_nodes;
        unsigned int _num_chairs;
        unsigned int _num_chairs_occupied;
        unsigned int _num_persons;  // number of Person objs that exists in the  graph
        Graph();

    public:
        // general constructor
        explicit Graph(GraphRepresenter graph);
        // TODO(DonaldKruse): add copy constructor

        // getters and setters for vertices, edges
        unsigned int get_num_nodes();
        unsigned int get_num_chairs();
        unsigned int get_num_chairs_occupied();
        unsigned int get_num_persons();
        std::vector<Vertex> get_nodes();
        GraphRepresenter get_graph_representer();


        // utilities
        bool are_neighbors(Vertex vertex1, Vertex vertex2);
        bool are_neighbors(unsigned int vertex1, unsigned int vertex2);
        void print_adjacency_lists();


        // TODO(DonaldKruse): insert and delete for nodes and edges
        void insert_adjlist(AdjacencyList adjlist);
        void delete_adjlist(AdjacencyList adjlist);


        // TODO(DonaldKruse): determine how and when to use a sparse matrix/data struct
        //      for example std::unordered_map has average constant-time complexity
        //      for lookup, insert, etc...

        ~Graph();
};

#endif  // GRAPH_H_
