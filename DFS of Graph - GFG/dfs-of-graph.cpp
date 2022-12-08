// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> dfs_traversal;
        bool vis[V] = {0};
        dfs(0, vis, adj, dfs_traversal);
        
        return dfs_traversal;
    }
    
    void dfs(int node, bool *vis, vector<int> adj[], vector<int> &dfs_traversal)
    {
        dfs_traversal.push_back(node);
        vis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it]) 
                dfs(it, vis, adj, dfs_traversal);
        }
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends