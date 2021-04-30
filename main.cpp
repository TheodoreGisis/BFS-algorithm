#include <iostream>
#include <vector>
#include <list>
#include <fstream>
using namespace std;
// creating a class
class Graph{

private:
        int V;
        list<int> *adj;
public:
    Graph(int V);
    void addEdge(int x, int y);
    void BFS(int startnode);
    
    
};
//method to add an edge in the list
void Graph::addEdge(int x, int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}
//Constractor
Graph::Graph(int V){
    int newV=V;
    adj = new list<int>[V];
}
//Here we start the BFS algorithm
void Graph::BFS(int startnode){
bool *visited = new bool [V];

for(int i=0; i<V; i++){
    visited[i]=false;
}

list<int> Q;

visited[startnode]=true;
Q.push_back(startnode);
list<int>::iterator i;
while(!Q.empty())
{
    int front =  Q.front();
    cout<<"We have visit "<< front<<endl; 
    Q.pop_front();
 for( i = adj[front].begin(); i!=adj[front].end(); i++){
    int position =*i;
     if(!visited[position]){
        visited[position]=true;
        Q.push_back(position);
     }
 }
}

}


int main()
{



//if you want to enable algorithm with different peaks just change the NewGraph.addEdge
    Graph NewGraph(5);
    NewGraph.addEdge(0,1);
    NewGraph.addEdge(0,2);
    NewGraph.addEdge(0,3);
    NewGraph.addEdge(1,2);
    NewGraph.addEdge(2,4);
    NewGraph.addEdge(3,3);
    NewGraph.addEdge(4,4);
    NewGraph.BFS(0);
    
     return 0;
}