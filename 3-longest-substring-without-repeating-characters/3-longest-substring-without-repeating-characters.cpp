class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(!n) return 0;
        unordered_map<char, int> m;   //create map to store frequency,(get to know all unique characters
        int i = 0, j = 0, ans = INT_MIN; 
        
        while(j < n)   
        {
            m[s[j]]++;                      // increase the frequency of the element as you traverse the string
            if(m.size() == j - i + 1)       // when map size is equal to the window size means suppose window size is 3 and map size is also three that means                                                  in map all unique characters are their
            {
                ans = max(ans, j - i + 1); 
            }
            // If the map size is less than the window size means there is some duplicate present like window size = 3 and map                                                 size = 2 means there is a duplicates
            while(m.size() < j - i + 1)           //so till the duplicates are removed completely
            {
                m[s[i]]--;              
                if(m[s[i]] == 0) m.erase(s[i]);        
                i++;                     
            }
            j++;                       
        }
        return ans;
    }
};