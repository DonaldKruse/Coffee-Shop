/* Example of how a graph can be built and accessed
 *
 *  by Donald Kruse
 */


#include <iostream>
#include <string>
#include <list>
#include <utility> // std::pair
#include <vector>

struct Vert {
    int val;
    std::string name;
    Vert(int v, std::string n) : val(v), name(n) {};
};


// adjacency list for a single vertex
typedef std::pair< Vert, std::vector<Vert > adjacency_list;


// This is the actual representation of the graph -- a list of adjacency lists.
// Order somewhat matters. May change later.
typedef std::list< adjacency_list > graph_representer;

using namespace std;

int main() {
    // individual vertices
    Vert e1(1, "one");
    Vert e2(2, "two");
    Vert e3(3, "three");
    Vert e4(4, "four");

    // each vertex has an associated adjacency list
    vector<Vert> v1 = { e1, e2, e3 };
    vector<Vert> v2 = { e2, e3, e4 };
    vector<Vert> v3 = { e3, e4, e1 };
    vector<Vert> v4 = { e4, e1, e2 };

    // pair that maps vertex to its adjacency list
    adjacency_list a1 =  {e1, v1};
    adjacency_list a2 =  {e2, v2};
    adjacency_list a3 =  {e3, v3};
    adjacency_list a4 =  {e4, v4};

    // a list of adjacency lists makes a graph
    graph_representer graph = { a1, a2, a3, a4 }; 

    // accessing the vertices
    for ( auto it = graph.begin(); it != graph.end(); it++ ) {
        // for convinience, assign for the first and second in the pair.
        // since the iterator really just points to an adjacency_list (std::pair)
        auto f = it->first;
        auto s = it->second;
         
        cout << "first: " << f.name << endl;
        cout << "second: " << s[0].name << endl;

        cout << "first: " << it->first.name << endl;
        cout << "second: " << it->second.size() << endl;
    }
    return 0;
}

