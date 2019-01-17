#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
//typedef std::unordered_map< Vertex, std::vector<Vertex> > AdjacencyList;
typedef std::pair< Vertex, std::vector< Vertex > > AdjacencyList;

// This is the actual representation of the graph -- a list of adjacency lists.
// Order somewhat matters. May change later.
typedef std::vector< AdjacencyList > GraphRepresenter;


int main() {
    // make the nodes
    Vertex v1(1, false, false, "one");    
    Vertex v2(2, false, false, "two");    
    Vertex v3(3, false, false, "three");    

    // each node has an adjacency list
    AdjacencyList a1 = std::make_pair(v1 , std::vector<Vertex> {v2,v3} );
    AdjacencyList a2 = std::make_pair(v2 , std::vector<Vertex> {v3,v1} );
    AdjacencyList a3 = std::make_pair(v3 , std::vector<Vertex> {v1,v2} );

    // list of AdjacencyList's is a graph
    GraphRepresenter graph = {a1,a2,a3};

    // access the things
    for (auto it = graph.begin(); it != graph.end(); it++ ) {
        auto val1 = it->first;
        auto val2 = it->second;
        std::cout << "first: " << val1.label << "; second (get size of vector): " << val2.size() << std::endl;
    }

    // use std::sort on a vector of structs
    Vertex v10(10, false, false, "");
    Vertex v11(11, false, false, "");
    Vertex v100(100, false, false, "");
    std::vector<Vertex> vec = {v100, v11, v10};

    std::cout << "Before sort, vec: ";
    std::vector<Vertex>::iterator iter;
    for (iter = vec.begin(); iter != vec.end(); iter++)
        std::cout << iter->label << " ";
    std::cout << std::endl;

    std::cout << "After sort..." << std::endl;
    std::sort(vec.begin(), vec.end());
    std::cout << "vec: ";
    for (iter = vec.begin(); iter != vec.end(); iter++)
        std::cout << iter->label << " ";
    std::cout << std::endl;

    // -- using std::find on vec --
    std::cout << "Using std::find to find the value '11' in vec..." << std::endl;
    int findval = 11;
    auto result = std::find(vec.begin(), vec.end(), findval);
    if (result != vec.end()) {
        std::cout << "Vec contains " << findval << "!" << std::endl;
        // use vec.begin() to find index and ptrdiff_t to avoid 
        // negative values
        ptrdiff_t index = result - vec.begin();
        std::cout << "index = " << index << std::endl;
    } else {
        std::cout << "Vec does NOT contains " << findval << "!" << std::endl;
    }


    // -- finding node from GraphRepresenter object --

    std::cout << std::endl;
    std::cout << "finding vertices with labels 1 and 2 through iteration..." << std::endl;
    std::cout << std::endl;
    unsigned int node1 = 1;
    unsigned int node2 = 2;
    std::vector<AdjacencyList>::iterator alp1;
    std::vector<AdjacencyList>::iterator alp2;
    for ( auto it = graph.begin(); it != graph.end(); it++ ) {
        std::cout << it->first.label;
        if ( it->first.label == node1 ) {
            std::cout << " <--found 1";
            alp1 = it;
        }
        if ( it->first.label == node2 ) {
            std::cout << " <--found 2";
            alp2 = it;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "using std::find_if..." << std::endl;

    auto found1 = std::find_if(graph.begin(), graph.end(),
                     [&node1](AdjacencyList& elem)
                             {return node1 == elem.first.label;});

    auto found2 = std::find_if(graph.begin(), graph.end(),
                     [&node2](AdjacencyList& elem)
                             {return node2 == elem.first.label;});

    // check if node1 is found
    if (found1 == graph.end())
        std::cout<< "node1 not found" << std::endl;
    else
        std::cout<< "node1 found" << std::endl;

    // check if node2 is found
    if (found2 == graph.end())
        std::cout<< "node2 not found" << std::endl;
    else
        std::cout<< "node2 found" << std::endl;

    // check for nonexistant node
    std::cout << "looking for nonexistant node..." << std::endl;
    unsigned int node404 = 404;
    auto found404 = std::find_if(graph.begin(), graph.end(),
                     [&node404](AdjacencyList& elem)
                             {return node404 == elem.first.label;});

    // check if node404 is found
    if (found404 == graph.end())
        std::cout<< "node404 not found" << std::endl;
    else
        std::cout<< "node404 found" << std::endl;


    return 0;
}
