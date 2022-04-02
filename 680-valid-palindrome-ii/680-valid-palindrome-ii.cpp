class Solution {
public:
    bool ispalindrome(string s, int i, int j){
        while(i < j) if(s.at(i++)!= s.at(j--)) return false;        
        return true;
    }
    bool validPalindrome(string s) {
        int i  = 0;
        int j = s.size()-1;
        while(i < j)
        {
            if(s.at(i) != s.at(j)) return ispalindrome(s, i+1, j) || ispalindrome(s, i, j-1);
            else {i++; j--;}
        }
        return true;
    }
};