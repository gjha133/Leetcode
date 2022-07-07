class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int min = INT_MAX;
        int closest;
        
        for(int num : nums)
        {
            if( abs(num) < min)
            {
                min = abs(num);
                closest = num;
            }
            else if( abs(num) == min)
            {
                if(closest < num) closest = num;
            }
        }
        
        return closest;
    }
};