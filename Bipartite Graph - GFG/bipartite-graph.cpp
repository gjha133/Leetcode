// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool bipartiteDFS(int node, vector<int> adj[], vector<int> &color)
    {
        if(color[node] == -1) color[node] = 1;  // If not visited, color it with 1 (can take 0 also)
        
        for(auto it : adj[node])
        {
            if(color[it] == -1)
            {
                color[it] = 1 - color[node];
                if(!bipartiteDFS(it, adj, color)) return false;
            }
            else 
            {
                if(color[it] == color[node]) return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color (V, -1);
	    
	    for(int i=0; i<V; i++)
	    {
	        if(color[i] == -1)  // color array will act as visited array. -1 = not visited
	        {
	            if(!bipartiteDFS(i, adj, color)) return false;
	            
	            // if function returns false, it will be true and it will return false
	        }
	    }
	    
	    return true;    // if function is true, it will return true at the end
	}
	

    // BFS CODE 
    /*
    bool bipartiteBFS(int src, vector<int> adj[], vector<int> &color)
    {
        queue<int> q;
        q.push(src);
        color[src] = 1;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node])
            {
                if(color[it] == -1)     // If not visited
                {
                    color[it] = 1 - color[node];    // 1 - prev (1-1 = 0 or 1-0 = 1)
                    q.push(it);
                }
                else if(color[it] == color[node]) // If visited and adjacent nodes have same color
                        return false;
            }
        }
        
        return true;    // If whole graph is traversed
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color (V, -1);
	    
	    for(int i=0; i<V; i++)
	    {
	        if(color[i] == -1)  // color array will act as visited array. -1 = not visited
	        {
	            if(!bipartiteBFS(i, adj, color)) return false;
	            
	            // if function returns false, it will be true and it will return false
	        }
	    }
	    
	    return true;    // if function is true, it will return true at the end
	}
    */

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends