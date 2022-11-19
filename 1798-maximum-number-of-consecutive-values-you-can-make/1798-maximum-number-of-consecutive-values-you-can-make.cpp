class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int sum = 0;        
        sort(coins.begin(), coins.end());
        
        for(int coin : coins)
        {
            if(sum + 1 >= coin) sum += coin;
            else break;
        }
        
        return ++sum;
    }
};