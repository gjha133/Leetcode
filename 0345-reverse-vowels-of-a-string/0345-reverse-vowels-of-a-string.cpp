class Solution {
public:
    bool isVowel(char c) {return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U';}
        
    string reverseVowels(string s) {
        int n = s.size();
        int start = 0, end = n-1;
        while(start <= end)
        {
            if(isVowel(s[start]) and isVowel(s[end]))
            {
                swap(s[start], s[end]);
                start++;    end--;
            }
            else if(!isVowel(s[start]))
                start++;
            else if(!isVowel(s[end]))
                end--;
        }
        
        return s;
    }
};