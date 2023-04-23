//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string s[], int n)
    {
        // your code here
        int ans = s[0].length();
        for(int i=1; i<n; i++){
            int j = 0;
            while(j<s[i].length() && s[i][j] == s[0][j]) j++;
            ans = min(ans, j);
        }
        
        return ans == 0 ? "-1" : s[0].substr(0, ans);
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends