class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long sum = 0, size = nums.size(), ans = 0, i = 0;
        
        while(sum < n)
        {
            // If i can make the sum + 1 using nums till i
            if(i < size and sum + 1 >= nums[i])
            {
                sum += nums[i];
                i++;
                // Add the nums[i] to current sum that I can make
            }
            else
            {
                // If can't make the sum + 1 using nums till i, then i will add the number == sum + 1 to the array/sum and increase the count
                sum += (sum + 1);
                ans++;
            }
        }
        
        return ans;
    }
};