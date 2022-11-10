class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(auto &c : s)
        {
            if(!s.empty() and c == '*')
                ans.pop_back();
            else 
                ans.push_back(c);       
        }
        
        return ans;
    }
};