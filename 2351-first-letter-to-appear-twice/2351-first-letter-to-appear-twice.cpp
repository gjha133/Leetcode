class Solution {
public:
    char repeatedCharacter(string s) {
        bool seen[26] = {0};
        
        for(auto c : s)
        {
            if(seen[c - 'a']) return c;
            else seen[c - 'a'] = true;
        }
        
        return false;
    }
};