class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char> s_t;
        unordered_map<char,char> t_s;
        
        for(int i=0; i<s.size(); i++)
        {
            // If both char are not mapped
            if(!s_t.count(s[i]) and !t_s.count(t[i]))
            {
                s_t[s[i]] = t[i];       //Map s[i]->t[i]
                t_s[t[i]] = s[i];       //Map t[i]->s[i]
            }
            // If s char is not mapped but t char is mapped
            else if(!s_t.count(s[i]) and t_s.count(t[i]))
                return false;
            // If s char is mapped to a different char than t char
            else if(s_t[s[i]] != t[i])
                return false;
        }
        
        return true;
        
    }
};