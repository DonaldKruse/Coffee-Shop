#include <queue>
#include <vector>

#include "Navigator.h"
#include "Graph.h"

// File: navigator.cpp
// Purpose: Class implementing Dijkstra's Algorithm for finding the shortest path in a graph.


// Construct Navigator with initial Graph
Navigator::Navigator(GraphRepresenter graph) {
    _my_Map = graph;
}

// Destructor
Navigator::~Navigator() {}

// Returns a list of vertices representing the shortest path from start to finish.
std::list<unsigned int> Navigator::search (unsigned int start, 
			  unsigned int finish) {
  std::list<unsigned int> val = {1, 2, 3};
  return val;
}

/*******************************************************
    // Uses Dijkstra's algorithm to search for the shortest path between to 
    // vertices in a graph.

    // TODO - Implement the following Pseudo-code from:
    //   https://en.wikipedia.org/wiki/Dijkstra's_algorithm 
    // 
    // function search(Graph, source): 
    // 
    //     create vertex set Q 
    // 
    //     for each vertex v in Graph:             
    // Initialization 
    //          dist[v] ← INFINITY                  
    // Unknown distance from source to v 
    //          prev[v] ← UNDEFINED                 
    // Previous node in optimal path from source 
    //          add v to Q                          
    // All nodes initially in Q (unvisited nodes) 
    // 
    //     dist[source] ← 0                        
    // Distance from source to source //     
    //     while Q is not empty: 
    //          u ← vertex in Q with min dist[u]    
    // Node with the least distance 
    //                                              
    // will be selected first 
    //          remove u from Q 
    //          
    //          for each neighbor v of u:           // where v is still in Q.  
    //              alt ← dist[u] + length(u, v) 
    //              if alt < dist[v]:               // A shorter path to v has been found 
    //                  dist[v] ← alt 
    //                  prev[v] ← u 
    // 
    //      return dist[], prev[]


    // TODO
    //     create vertex set Q 
    // TODO -- int size = <size of graph>
    priority_queue <int> distance = new priority_queue<int>(new[size]{INT_MAX});
    distance[start] = 0;`
    // 
    int* previous = new ???
    //     for each vertex v in Graph:             
    // Initialization 
    //          dist[v] ← INFINITY                  
    // Unknown distance from source to v 
    //          prev[v] ← UNDEFINED                 
    // Previous node in optimal path from source 
    //          add v to Q                          
    // All nodes initially in Q (unvisited nodes) 
    // 
    //     dist[source] ← 0                        
}
*****************************************************/
