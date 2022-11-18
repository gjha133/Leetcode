//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    map<int, int> mp;
	    vector<int> sorted;
	    
	    for(int i = 0; i < n; i++)
	    {
	        mp[nums[i]] = i;
	        sorted.push_back(nums[i]);
	    }
	    
	    sort(sorted.begin(), sorted.end());
	    
	    int count = 0;
	    for(int i = 0; i < n; i++)
	    {
	        if(nums[i] != sorted[i])
	        {
	            nums[mp[sorted[i]]] = nums[i];
	            mp[nums[i]] = mp[sorted[i]];
	            mp[sorted[i]] = i;
	            nums[i] = sorted[i];
	            count++;
	        }
	    }
	    
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends