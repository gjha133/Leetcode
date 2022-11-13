class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int i = 0, j = 0, n = s.size(), lastIndex = 0;
        
        while(j < n)
        {
            // Find the starting index of word
            while(j < n && s[j] == ' ') j++;
            
            int startIndex = i;
            
            // Store the complete word...
            while(j < n && s[j] != ' '){
                s[i++] = s[j++];
                lastIndex = i;
            }
            
            // Reverse the word
            reverse(s.begin() + startIndex, s.begin() + i);
            s[i++] = ' '; // after every word we need space [" "]
        }
        
        // Resize the string to last index...
        s.resize(lastIndex);
        return s;

    }
};