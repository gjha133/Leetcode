class Solution {
public:
    int pivotIndex(vector<int>& nums) {   
        int totalSum = 0;
        for(int num : nums) totalSum += num;
        
        int sum = 0;
        // totalSum = leftSum + Value at Pivot + rightSum
        // totalSum = 2*sum + Value at Pivot
        // 2*sum = totalSum - Value at Pivot
        
        for(int i=0; i<nums.size(); i++)
        {
            
            if(2*sum == totalSum - nums[i]) return i;
            sum += nums[i];
            
        }
        
        return -1;
        
        
        
    }
};