class Solution {
public:
    string getSmallestString(int n, int k) {
       // Initialising a string with all 'a' and subtracting the value of all a's from k.
        string ans(n, 'a');     k = k - n;
        while(k > 0)
        {
            n--;
            ans[n] = ans[n] + min(25, k);
            k = k - min(25,k);
        }
        
        return ans;
        
    }
};