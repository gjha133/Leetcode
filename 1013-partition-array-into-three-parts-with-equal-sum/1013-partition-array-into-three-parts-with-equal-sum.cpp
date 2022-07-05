class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int totalSum = 0;
        for(int a : arr) totalSum += a;
        
        if(totalSum % 3 != 0) return false;
        int runningSum = 0, individualSum = totalSum/3, count = 0;
        
        for(int num : arr)
        {
            runningSum += num;
            if(runningSum == individualSum)
            {
                runningSum = 0;
                count++;
            }            
        }
        
        return count >= 3;
    }
};