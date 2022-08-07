class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> freq;
        for(auto c : s) freq[c]++;
        
        int n = s.size(), bal = n/4;
        
        if(isBalanced(freq, bal)) return 0;
        
        int ans = INT_MAX, i = 0, j = 0;
        while(j < n)
        {
            freq[s[j]]--;
            while(i <= j and isBalanced(freq, bal))
            {
                int window = j - i + 1;
                ans = min(ans, window);
                freq[s[i]]++;
                i++;
            }
            j++;
        }
        
        return ans;
        
    }
    
    bool isBalanced(unordered_map<char, int> &freq, int limit)
    {
        return freq['Q'] <= limit and freq['W'] <= limit and
            freq['E'] <= limit and freq['R'] <= limit;
    }
};