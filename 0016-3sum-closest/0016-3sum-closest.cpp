class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        
        int ans = nums[0]+nums[1]+nums[2], n = nums.size();
        
        for(int i = 0; i < n-2; i++)
        {
            int start = i + 1, end = n-1;
            while(start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == target) return sum;
                if(abs(target - sum) < abs(target - ans))
                    ans = sum;
                
                if(sum < target) 
                    start++;
                else 
                    end--;
            }
        }
        
        return ans;
    }
};