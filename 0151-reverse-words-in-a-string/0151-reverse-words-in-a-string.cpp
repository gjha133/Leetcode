class Solution {
public:
    string reverseWords(string s) {        
        int i = 0, j = 0, n = s.size(), lastIndex = 0;
        string ans = "", temp;
        
        while(j < n)
        {
            temp = "";
            // Find the starting index of word
            while(j < n && s[j] == ' ') j++;
            
            
            // Store the complete word...
            while(j < n && s[j] != ' '){
                temp += s[j++];
            }
            
            if(ans == "") ans += temp;
            else
            {
                temp += " " + ans;
                ans = temp;
            }
        }
        
        while(i < ans.size() and ans[i] == ' ') i++;
        
        
        return ans.substr(i, ans.size() - i);

    }
};