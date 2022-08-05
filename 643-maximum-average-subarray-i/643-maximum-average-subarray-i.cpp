class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0;
        double sum = 0;
        double mx = INT_MIN;
        
        while(j < n)
        {
            sum += nums[j];
            if(j - i + 1 == k)
            {
                mx = max(mx, sum);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        
        return mx/k;
    }
};