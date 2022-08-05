class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int n = str.size(), i = 0, j = 0;
        int ans = 0;
        while(j < n)
        {
            if(j - i + 1 == k)
            {
                string s = str.substr(i,k);
                int temp = stoi(s);
                if(temp != 0 and num % temp == 0) ans++;
                i++;
            }
            j++;
        }
        
        return ans;
    }
};