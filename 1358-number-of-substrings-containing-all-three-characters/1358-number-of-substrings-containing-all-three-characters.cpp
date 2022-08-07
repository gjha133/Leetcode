class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0 , j = 0 , end = s.size() - 1;
        unordered_map<char,int> map;
        int ans = 0;
        
        while(j != s.size())
        {
            map[s[j]] += 1; // adding new element to window
            
            while(map['a'] and map['b'] and map['c'])
            {
                ans += end - j + 1;
                map[s[i]]--; 
                i++;
            }
            j++;
        }
        return ans;
    }
};