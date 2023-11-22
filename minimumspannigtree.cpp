#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int spanningTree(int v, vector<vector<pair<int, int>>> &adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> vis(v, 0);
    pq.push({0, 0}); // Starting from node 0 with weight 0

    int sum = 0;

    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        int node = t.second;
        int wt = t.first;

        if (vis[node] == 1)
            continue;

        vis[node] = 1;
        sum += wt;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (!vis[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    return sum;
}

int main() {
    int v, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<pair<int, int>>> adj(v);

    cout << "Enter the edges (u, v, weight):" << endl;
    for (int i = 0; i < e; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    int minSpanningTreeWeight = spanningTree(v, adj);

    cout << "Weight of the minimum spanning tree: " << minSpanningTreeWeight << endl;

    return 0;
}
