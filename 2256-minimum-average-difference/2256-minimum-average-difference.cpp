class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size(), mn = INT_MAX, index = -1;
        
        long long sumFromFront = 0, sumFromEnd = 0;
        for (auto& num : nums) sumFromEnd += num;
        
        for (int i = 0; i < n; i++) 
        {
            sumFromFront += nums[i];
            sumFromEnd -= nums[i];
            int start = sumFromFront / (i+1); // average of the first i + 1 elements.
            int end = (i == n-1) ? 0 : sumFromEnd / (n-i-1); // average of the last n - i - 1 elements.
            
            if (abs(start-end) < mn) 
            {
                mn = abs(start-end);
                index = i;
            }
        }
        return index;
        
    }
};