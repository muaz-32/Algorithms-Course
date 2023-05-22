#include "bits/stdc++.h"
using namespace std;
int row;
int col;
int matrix[1000][1000];
vector<list<pair<int, int>>> adj;
typedef pair<int, int> pii;


vector<int> dijkstra(const vector<list<pii>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INF);  
    dist[source] = 0;  

    priority_queue<pii, vector<pii>, greater<pii>> pq;  

    pq.push({0, source}); 

    while (!pq.empty()) {
        int u = pq.top().second;  
        int currDist = pq.top().first;
        pq.pop();

        
        if (currDist > dist[u])
            continue;
      
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}



int main(void){
    cin >> row;
    cin >> col;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> matrix[i][j];
        }
    }
    adj.resize(row * col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(j != col - 1)
                adj[i*col + j].push_back({i*j + j + 1, matrix[i][j + 1]});
//            if(j != 0)
//                adj[i*col + j].push_back({i*j + j - 1, matrix[i][j - 1]});
            if(i != row - 1)
                adj[i*col + j].push_back({i*j + j + col, matrix[i + 1][j]});
//            if(i != 0)
//                adj[i*col + j].push_back({i*j + j - col, matrix[i - 1][j]});
        }
    }
    for(int i = 0; i < adj.size(); i++){
        cout << i << endl;
        for(auto j = adj[i].begin(); j != adj[i].end(); j++){
            cout << (*j).first << " " << (*j).second << endl;
        }
        cout << endl;
    }
  
    vector<int> m = dijkstra(adj, 0);
    cout << m[m.size() - 1];
    return 0;
}
