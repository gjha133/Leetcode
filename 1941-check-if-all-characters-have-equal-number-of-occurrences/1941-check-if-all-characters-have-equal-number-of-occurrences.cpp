class Solution {
public:
    bool areOccurrencesEqual(string s) {
        
        // Freq Array
        int freq[26] = {0};
        // Building the freq array     
        for(char &c : s) freq[c - 'a']++;        
        
        // Frequency of first term in the string
        int count = freq[s[0] - 'a'];
        // Comapring count
        for(int i=0; i<26; i++)
        {
            if(count != freq[i] and freq[i] != 0) return false;
        }
        
        return true;
    }
};