class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, n = s.size();
        while(j < n)
        {
            while(j < n and s[j] != ' ') j++;
            int index = j;
            reverse(s.begin() + i, s.begin() + index);
            j++;    i = j;
        }
        
        return s;
    }
};