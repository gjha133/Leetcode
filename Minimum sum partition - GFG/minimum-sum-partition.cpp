//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int totalSum = 0;
        for(int i = 0; i < n; i++) totalSum += arr[i];
    
        int k = totalSum;
        vector<vector<bool>> dp (n, vector<bool> (k+1, false));
    
        // With sum = 0, entry = 1.
        for(int i=0; i<n; i++) dp[i][0] = true;
    
        if(arr[0] <= k) dp[0][arr[0]] = true;
    
        for(int i = 1; i<n; i++)
        {
            for(int j = 1; j <=k; j++)
            {
                bool notTake = dp[i-1][j];
                bool take = false;
                if(arr[i] <= j) take = dp[i-1][j - arr[i]];
    
                dp[i][j] = take or notTake;
            }
        }
        /*
        for(int i = 0; i < n; i++)
        {
            for(int sum = 0; sum <= totalSum; sum++)
            {
                cout << dp[i][sum] << " ";
            }
            
            cout << endl;
        }
        */
        // dp[n-1][0->.....totalSum]
    
        int mn = 1e9;
        for(int s1 = 0; s1 <= totalSum/2; s1++)
        {
            if(dp[n-1][s1] == true)
            {
                int s2 = totalSum - s1;
                mn = min(mn, abs(s1 - s2));
            }
        }
    
        return mn;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends