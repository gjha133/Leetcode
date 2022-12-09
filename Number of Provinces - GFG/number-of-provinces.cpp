//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void DFS(int src, vector<bool>& vis, vector<int> adj[]) {
        vis[src] = true;
        for (int u : adj[src]) {
            if (!vis[u]) {
                DFS(u, vis, adj);
            }
        }
    }
    int numProvinces(vector<vector<int>> mat, int V) {
        vector<bool> vis(V, false);
        vector<int> adj[V];
        
        // convert to adj list and find connected components
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (mat[i][j] == 1 and i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                DFS(i, vis, adj);
            }
        }
        return cnt;
    }
}; 

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends