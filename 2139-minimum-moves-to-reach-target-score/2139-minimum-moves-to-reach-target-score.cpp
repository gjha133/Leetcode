class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while(target and maxDoubles)
        {
            if(target & 1) target--;
            else
            {
                maxDoubles--;
                target /= 2;
            }
            
            ans++;
        }
        
        return target - 1 + ans;
    }
};