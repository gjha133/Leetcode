// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    // BFS Function
    bool bfs(int i, int V, vector<bool> &vis, vector<int> adj[]){
        
        queue<pair<int, int>> q;
        q.push({i, -1});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int prev = q.front().second;
            vis[node] = 1;
            q.pop();
            
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if(prev != it){
                    return true;
                }
            }
        }
        return false;
    }
    
    // DFS Function
    bool dfs(int node, int parent, vector<bool> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, node, vis, adj)) return true;
            }
            else if(it != parent) return true;
        }
        
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(
                    //bfs(i, V, vis, adj)
                    dfs(i, -1, vis, adj)
                    ){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends