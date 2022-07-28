class Solution {
public:
    bool checkString(string s) {
        
        int B = 0;
        for(auto &c : s)
        {
            if(B >= 1 and c == 'a') return false;
            if(c == 'b') B++;
        }
        
        return true;
    }
};