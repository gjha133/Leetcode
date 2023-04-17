class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.rbegin(), s.rend());
        sort(g.rbegin(), g.rend());
        
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