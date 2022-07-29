class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int freq[101] = {0};
        
        for(int num : nums) freq[num]++;
        
        
        int pair = 0, not_pair = 0;
        for(int count : freq)
        {
            pair += count/2;
            if(count & 1) not_pair++;            
        }
        
        return {pair, not_pair};
    }
};