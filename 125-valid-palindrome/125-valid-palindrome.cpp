class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        int start = 0, end = s.size()-1;
        while(start < end)
        {
            if(!isalnum(s[start])) {start++; continue;}
            if(!isalnum(s[end]))   {end--;   continue;}
            if( tolower(s[start++]) != tolower(s[end--]))  return false;            
        }
        
        return true;
        
    }
    
    bool isValid(char c)
    {
        return ((c >= 'A' and c <= 'Z') and (c >= 'a' and c <='z') and (c >= '0' and c <= '9'));
    }
};