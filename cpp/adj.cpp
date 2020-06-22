/**
 *@inci.cpp
 * adjacency matrix: the matrix between nodes
 */

#include <iostream>
#include <vector>
#include <utility>
void print_graph(const std::vector<std::vector<int> > &adj);
void addEdge(std::vector<std::vector<int> >& adj, int u, int v);

int main()
{
// Initialise array to hold adjacency matrix, vec<>s is already dynamic
    std::vector<std::vector<int> > adj(11, std::vector<int>(11));
    addEdge(adj,0,1);     // edge from node 0 to node 1
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,7,8);
    addEdge(adj,8,9);
    addEdge(adj,9,10);
    addEdge(adj,10,6);
    print_graph(adj);
}

void print_graph(const std::vector<std::vector<int> >& adj)
{
    for(std::size_t i = 0; i < adj.size(); i++ )
    {
        for(std::size_t j = 0 ; j < adj[i].size(); j++ )
        {
            std::cout << adj[i][j]<< "  ";
        }
        std::cout << std::endl;
    }
}


void addEdge(std::vector<std::vector<int> >& adj, int u , int v)
{
    adj[u][v]=1;
    adj[v][u]=1;
}