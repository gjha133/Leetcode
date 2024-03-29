class Solution {
public:
    string largestGoodInteger(string num) {
        char ans = 0;
        for(int i = 2; i < num.size(); ++i)
            if (num[i] == num[i - 1] && num[i] == num[i - 2])
                ans = max(ans, num[i]);
        return ans == 0 ? "" : string(3, ans);
    }
};