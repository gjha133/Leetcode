class Solution {
public:
    
    bool static comp(int &a, int &b)
    {
        return a > b;
    }
    
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort(s.rbegin(), s.rend());
        // sort(g.rbegin(), g.rend());
        
        sort(s.begin(), s.end(), comp);
        sort(g.begin(), g.end(), comp);
        
        int sL = s.size(), gL = g.size();
        int idx = 0, happy = 0;
        for(int i = 0; i < gL; i++) {
            if(idx < sL and g[i] <= s[idx]) {
                happy++;
                idx++;
            }
        }
        
        return happy;
    }
};