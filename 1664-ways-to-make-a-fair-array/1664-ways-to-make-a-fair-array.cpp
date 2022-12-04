class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size(), even = 0, odd = 0, ans = 0;
        
        vector<int> evenSum(n+1, 0), oddSum(n+1, 0);
        
        //Build presum arrays
        for(int i = n-1; i >= 0; i--)
        {
            i&1 ? oddSum[i] += nums[i] : evenSum[i] += nums[i];
            
            oddSum[i] += oddSum[i+1];
            evenSum[i] += evenSum[i+1];
        }
        
        
        /*
        for(int num : evenSum) cout << num << " ";
        cout << endl;
        for(int num : oddSum) cout << num << " ";
        */
        
        
        for(int i = 0; i < n; i++)
        {
            even + oddSum[i+1] == odd + evenSum[i+1] ? ans++ : ans = ans;
            
            i&1 ? odd += nums[i] : even += nums[i];
        }
        
        return ans;
        
    }
};