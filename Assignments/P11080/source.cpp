#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{  
    int T;
    cin >> T;
    while ( T-- )
    {
        int v, e;
        cin >> v >> e;
        
        vector<vector<int> > G(v);
        vector<int> color(v, 2);
        bool isBipartite = true;
        
        while ( e-- )
        {
            int f, t;
            cin >> f >> t;
            G[f].push_back(t);
            G[t].push_back(f);
        }

        int totalCount = 0;
        for (int j = 0; j < G.size() && isBipartite;j++)
        {
            if (color[j] != 2)
                continue;

            queue<int> q;
            int count[2] = {0};
            color[j] = 0;
            ++count[color[j]];
            q.push(j);
            while (!q.empty() && isBipartite)
            {
                int u = q.front();
                q.pop();
                for (int i = 0; i < G[u].size();i++)
                {
                    int v = G[u][i];
                    if (color[v] == color[u])
                    {
                        isBipartite = false;
                        break;
                    }
                    else if (color[v] == 2)
                    {
                        color[v] = 1 - color[u]; 
                        ++count[color[v]];
                        q.push(v);
                    }
                }
            }
            
            totalCount += max(1, min(count[0], count[1]));
        }

        if (isBipartite)
            cout << totalCount << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}