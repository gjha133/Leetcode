//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<vector<int>> ans;
        vector<int> v;
        
        f(v, ans, n, n);
        
        return ans;
    }
    
    void f(vector<int>& v, vector<vector<int>>&ans, int i, int total)
    {
        if(total == 0)
        {
            ans.push_back(v);
            return;
        }
        
        if(i == 0) return;
        
        if(i <= total)
        {
            v.push_back(i);
            f(v, ans, i, total - i);
            v.pop_back();
        }
        
        f(v, ans, i-1, total);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends