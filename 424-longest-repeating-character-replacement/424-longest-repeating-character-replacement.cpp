class Solution {
public:
    int characterReplacement(string s, int k) {
        int mx = 0, sum = 0, i = 0, j = 0, n = s.size();
        int freq[26] = {0};
        while(j < n)
        {
            freq[s[j] - 'A']++;
            int maxfreq = maxF(freq);
            if(j - i + 1 - maxfreq <= k) mx = max(mx, j - i + 1);
            else
            {
                while(j - i + 1 - maxfreq > k)
                {
                    freq[s[i] - 'A']--;
                    i++;
                }
            }
            j++;
        }
        
        return mx;
    }
    
    int maxF(int *freq)
    {
        int mx = 0;
        for(int i=0; i<26; i++) mx = max(mx, freq[i]);
        return mx;
    }
};