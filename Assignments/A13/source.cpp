#include <map>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

# define INF 0x3f3f3f3f

int Time;
 
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
  
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;
  
public:
    Graph(int V);  // Constructor
  
    // function to add an edge to graph
    void addEdge(int u, int v, int w);
  
    // prints shortest path from s
    void shortestPath(int s);
};
  
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
  
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
  
// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
  
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);
  
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;
  
    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
  
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
  
            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
  
    // Print shortest distances stored in dist[]
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; ++i)
        //printf("%d \t\t %d\n", i, dist[i]);
        cout << i + 1 << "       " << dist[i] << endl;
}

int main(){
    
  freopen("infile", "r", stdin);
  freopen("outfile", "w", stdout);

  int TC, N, E, T, M;
  string blank;

  cin >> TC;

  while(TC--){
    getline(cin,blank);
    int start, finish, time;
    
    if(blank.length() == 0){
      cin >> N;
      Graph G(N);
      //cout << N << " ";
      cin >> E;
      //cout << E << " ";
      cin >> Time;
      //cout << T << " ";
      cin >> M;
      //cout << M << endl;
      for(int i = 0;i < M;i++){
        cin >> start >> finish >> time;
        //addEdge(G,start,finish);
        G.addEdge(start,finish,time);
        //G[start].push_back(finish,time);
        //G[finish].push_back(make_pair(start,time));
        //cout << G[start][finish] << endl;
        cout << start << "," << finish << "," << time << endl; 
      }
      
      //for (i = G->begin(); i != G->end(); ++i){
        //cout << i->first << i->second << endl;
      //}
      cout << E << endl;
      G.shortestPath(0);
      //G.printGraph();
    }
    cout << endl;
    //for(int i = 0;i < N;i++){
      //G[i].clear();
    //}
    
  }



    return 0;
}