class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int k = sum - x;
        if(x > sum) return -1;
        int mx = -1, i = 0, j = 0, n = nums.size();
        int cur = 0;
        while(j < n)
        {
            cur += nums[j];            
            while(cur > k)
            {
                cur -= nums[i];
                i++;
            }
            if(cur == k) mx = max(mx, j - i + 1);
            j++;
        }
        
        if(mx == -1) return -1;
        return n - mx;
    }
    
   
};