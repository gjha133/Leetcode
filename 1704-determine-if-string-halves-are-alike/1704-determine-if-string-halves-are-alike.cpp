class Solution {
public:
    bool halvesAreAlike(string s) {
        int vowels = 0, n = s.size();
        for(int i = 0; i < n; i++)
        {   
            s[i] = tolower(s[i]);
            if(i < n/2)
            {
                if(s[i] == 97 or s[i] == 101 or s[i] == 105 or s[i] == 111 or s[i] == 117)
                      vowels++;                  // counting for the first half of the string
            }
            else
            {
                if(s[i] == 97 or s[i] == 101 or s[i] == 105 or s[i] == 111 or s[i] == 117)
                     vowels--;            // reducing the count if occures in second half of the string 
            }     
        } 
       return vowels == 0;
    }
};