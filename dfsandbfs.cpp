#include<iostream>
using namespace std;
#include<vector>
#include<queue>
vector<int>BFSograph(vector <int> adj[],int n, int start ){
    int vis[n]={0};
    vis[start]=1;
    queue<int>q;
    q.push(start);
    vector<int>bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
   
    }
    
    return bfs;
    
}

void dfs(int node, vector <int> adj[],int vis[],vector<int> &ls){
    vis[node]=1;
    ls.push_back(node);
    // traverse the neighbours
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
    
}
vector<int> DFSograph(vector <int> adj[],int n, int start){
    int vis[n]={0};
    vector<int> ls;
    int s = start;
    dfs(s , adj, vis, ls);
    return ls;
}


int main() {
    int n, m;
    cout << "Enter the number of vertices and edges" << endl;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Printing the adjacency list" << endl;

    for (int i = 1; i <= n; i++) {
        cout << "Adjacency list for vertex " << i << ": ";
        for (auto it : adj[i]) {
            cout << it << " ";
        }
        cout << endl;
    }
    
    int start ;
    cout << "Enter the starting vertex for BFS and DFS"<<endl;
    cin >>start;
    vector<int> ans1;
     vector<int> ans2;
    
  ans1 =   BFSograph(adj,n,start);
  
  for(int i=0;i<ans1.size();i++){
      cout << ans1[i];
      cout << endl;
      
  }
  
  ans2 = DFSograph(adj,n,start);
        
    for(int i=0;i<ans2.size();i++){
      cout << ans2[i];
      cout << endl;
      
  }
  
        
    

    return 0;
}