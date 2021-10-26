// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency list representation of the graph
#include <iostream>
#include <limits.h>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <string>
#include <utility>
#include <set>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

# define INF 0x3f3f3f3f
int V;

// A utility function to print the constructed distance array
void printSolution(int dist[])
{
	cout <<"Vertex \t Distance from Source" << endl;
	for (int i = 1; i <= V; i++)
		cout << i << " \t\t"<<dist[i]<< endl;
}


void dijkstra(vector<pair<int,int> > adj[], int src,int time)
{
  priority_queue <pair<int, int>> pq;
  //int N = V;
	int dist[101];
  
  for(int i = 1;i <= V;i++){
    dist[i] = INF;
  }
  pq.push(make_pair(src,0));
  dist[src] = 0;

  int v, t, u, w, count = 0;
  while(!pq.empty()){
    
    v = pq.top().first;
    t = pq.top().second;
    pq.pop();
    
    for (int i = 0; i < adj[v].size(); i++)
    {
      u = adj[v][i].first;
      w = adj[v][i].second;    

      if(dist[v] + w < dist[u]){
              
        dist[u] = dist[v] + w;
        pq.push(make_pair(u,dist[u]));
      }
    }

  }
  
  for(int i = 1;i <= V;i++){
    if(dist[i] <= time){
      count++;
    }
  }

  cout << count;
}

void addEdge(vector<pair<int,int>>adj[], int u, int v,int w)
{
    adj[u-1].push_back(make_pair(v,w));
    adj[v-1].push_back(make_pair(u,w));
}

void printGraph(vector<pair<int,int> > adj[], int V)
{
    int v, w;
    for (int u = 1; u <= V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}


int main()
{
  int TC;

  freopen("infile", "r", stdin);
  freopen("outfile", "w", stdout);

  cin >> TC;

  for(int i = 0; i < TC;i++){

    string blank;
    getline(cin,blank);
    
    if(blank.empty()){
      int E = 0, T = 0, M = 0;
      cin >> V;
      //V = N;
      vector<pair<int,int>>G[101];
      cin >> E >> T >> M;

      for(int i = 0;i < M;i++){
        int start, finish, time;
        cin >> start >> finish >> time;
        G[start].push_back(make_pair(finish,time));
        G[finish].push_back(make_pair(start,time));
      }

      dijkstra(G,E,T);
        
    }
    if(i == TC - 1){
      cout << "\n";
    }
    else cout << "\n\n";
  }

	return 0;
}

