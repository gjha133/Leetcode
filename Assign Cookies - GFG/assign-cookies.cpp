//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz) {
        // code here
        sort(greed.rbegin(), greed.rend());
        sort(sz.rbegin(), sz.rend());
        
        int j = 0, children = 0;
        for(int i = 0; i < N; i++) {
            if(j < M and greed[i] <= sz[j]) {
                children++;
                j++;
            }
        }
        
        return children;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends