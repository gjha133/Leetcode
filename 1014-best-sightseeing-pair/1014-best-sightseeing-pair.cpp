class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0, cur = 0;
        for (int num : values) {
            res = max(res, cur + num);
            cur = max(cur, num) - 1;
        }
        return res;
    }
};