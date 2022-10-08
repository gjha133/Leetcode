class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(char c : s) freq[c]++;
        
        int odd = 0;
        for(auto [c , x] : freq) if(x&1) odd++;
        
        return s.size() - odd + (odd > 0);
    }
};