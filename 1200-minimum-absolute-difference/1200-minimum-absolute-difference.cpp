class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& A) {
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        int minDiff = INT_MAX, curDiff;
        for(int i = 1; i < size(A); i++) {
            auto [a, b] = minmax(A[i], A[i-1]);                 // a and b will hold min and max amongst A[i] and A[j]
            curDiff = b - a;
            if(curDiff == minDiff) ans.push_back({a, b});       // push if equal to MAB found till now
            else if(curDiff < minDiff) {                        // if current diff < MAB, update it and only keep current pair in ans
                minDiff = curDiff;
                ans = {{a, b}};
            }
        }
        return ans;
    }
};