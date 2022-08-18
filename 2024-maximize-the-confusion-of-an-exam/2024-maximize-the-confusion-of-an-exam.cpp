class Solution {
public:
    int solve(string &s, char c, int &k){
        
      int i = 0, j = 0, mx = 0, n = s.size(), count = 0;
      while(j < n)
      {
            if(s[j] == c) count++;
            while(count > k)
            {
                if(s[i] == c) count--;
                i++;
            }
            mx = max(j - i + 1, mx);
            j++;
       }
       return mx;
    }
    
    int maxConsecutiveAnswers(string s, int k) 
    {
      return max(solve(s,'F',k),solve(s,'T',k));  
    }
};