#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <utility> // std::pair


/* a Vertex that is used in the Graph class
 *
 * Should only contain public data and no
 * information about neighbors, connections, etc.
 */
struct Vertex {
    unsigned int label;   // unique ID for the node -- starts from zero
    bool is_chair;        // is this node a chair
    bool is_occupied;     // is the chair occupied
    std::string name;     // optional name for the node

    // constructor
    Vertex(unsigned int vlabel,
           bool vis_chair,
           bool vis_occupied,
           std::string vname) :

           label (vlabel),
           is_chair (vis_chair),
           is_occupied (vis_occupied),
           name (vname)
           {}

    // operator overloading -- necessary if the struct is a key in a map
    //bool const operator==(const Vertex &v) const {
    //    return label == v.label;
    //}

    bool const operator<(const Vertex &v) const {
        return label < v.label;
    }
};

// adjacency list for a single Vertex
//typedef std::unordered_map< Vertex, std::vector<Vertex> > adjacency_list;
typedef std::pair< Vertex, std::vector< Vertex > > adjacency_list;

// This is the actual representation of the graph -- a list of adjacency lists.
// Order somewhat matters. May change later.
typedef std::vector< adjacency_list > graph_representer;


int main() {
    // make the nodes
    Vertex v1(1, false, false, "one");    
    Vertex v2(2, false, false, "two");    
    Vertex v3(3, false, false, "three");    

    // each node has an adjacency list
    adjacency_list a1 = std::make_pair(v1 , std::vector<Vertex> {v2,v3} );
    adjacency_list a2 = std::make_pair(v2 , std::vector<Vertex> {v3,v1} );
    adjacency_list a3 = std::make_pair(v1 , std::vector<Vertex> {v1,v2} );

    // list of adjacency_list's is a graph
    graph_representer graph = {a1,a2,a3};

    // access the things
    for (auto it = graph.begin(); it != graph.end(); it++ ) {
        auto val1 = it->first;
        auto val2 = it->second;
        std::cout << "first: " << val1.label << "; second (get size of vector): " << val2.size() << std::endl;
    }
    return 0;
}

