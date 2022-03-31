// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
   	int  minimum_difference(vector<int>nums){
   	    // Code here
   	    sort(nums.begin(), nums.end());
   	    int diff = INT_MAX;
   	    for(int i=0; i<nums.size()-1; i++)
   	    {
   	        diff = min(diff, ( abs(nums[i] - nums[i+1]) ) );
   	    }
   	    
   	    return diff;
   	}    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < nums.size(); i++)cin >> nums[i];
		Solution ob;
		int ans = ob.minimum_difference(nums);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends