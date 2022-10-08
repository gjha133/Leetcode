class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char c : n)
        {
            if(c == '9') return 9;
            ans = max(ans, c - '0');
        }
        
        return ans;
    }
};