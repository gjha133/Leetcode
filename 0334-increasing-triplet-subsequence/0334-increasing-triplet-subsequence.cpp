class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_min = INT_MAX, second_min = INT_MAX;
        for(int num : nums)
        {
            if(num <= first_min) first_min = num;             // First min found
            else if(num <= second_min) second_min = num;        // Second min found
            else return true;                   // If third min found then we have our increasing triplet subsequence
        }
        
        return false;
    }
};