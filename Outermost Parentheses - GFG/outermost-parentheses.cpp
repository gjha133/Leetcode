//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        string ans = "";
        int parenthesis = 0, start = 0;
        for(int i = 0; i < s.size(); i++) {
            if(!parenthesis) start = i;
            
            if(s[i] == '(') parenthesis++;
            else if(s[i] == ')') parenthesis--;
            
            if(!parenthesis) {
                string temp = s.substr(start + 1, i - start - 1);
                ans += temp;
            }
        }
        
        return ans;  
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends