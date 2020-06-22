/**
 *@inci.cpp
 * Incidence matrix: the matrix between nodes and edges
 */

#include<iostream>
#include<vector>
#include<utility>
void displayMatrix(const std::vector<std::vector<int> >& inc);
void add_edge(std::vector<std::vector<int> >& inc, int u, int v);
int ed_no=0;

int main() 
{
// Initialise array to hold incidence matrix, vec<>s is already dynamic
   std::vector <std::vector<int> > inc(11, std::vector<int>(12));
//there are 3 vertices and 4 edges in the graph pila has
   add_edge(inc, 0, 1);
   add_edge(inc, 0, 6);
   add_edge(inc, 0, 7);
   add_edge(inc, 1, 2);
   add_edge(inc, 2, 3);
   add_edge(inc, 3, 4);
   add_edge(inc, 4, 5);
   add_edge(inc, 4, 8);
   add_edge(inc, 5, 6);
   add_edge(inc, 6, 10);
   add_edge(inc, 7, 8);
   add_edge(inc, 8, 9);
   add_edge(inc, 9, 10);
   displayMatrix(inc);
}

void displayMatrix(const std::vector<std::vector<int> >& inc) 
{
   for(std::size_t i = 0; i < inc.size(); i++)
   { 
      for(std::size_t j = 0; j < inc[i].size(); j++) 
      {
         std::cout << inc[i][j] << "  ";
      }
      std::cout << std::endl;
   }
}
void add_edge(std::vector<std::vector<int> >& inc, int u, int v) 
{//function to add edge into the matrix with edge number
   inc[u][ed_no]=1;
   inc[v][ed_no]=1;
   ed_no++; //increase the edge number
}