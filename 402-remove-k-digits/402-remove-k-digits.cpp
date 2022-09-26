class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        
        for(char c : num)
        {
            while(ans.size() and k and ans.back() > c)
            {
                ans.pop_back();
                k--;
            }
            
            if(ans.size() or c != '0') ans.push_back(c);
        }
        
        cout << ans << endl;
        
        while(ans.size() and k--) ans.pop_back();
        
        return ans.empty() ? "0" : ans;
    }
};