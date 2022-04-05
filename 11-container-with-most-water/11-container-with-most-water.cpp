class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), start = 0, end = n-1, ans = INT_MIN;
        while(start < end)
        {
            ans = max(ans, min(height[start], height[end]) * (end - start));
            height[start] < height[end] ? start++ : end--;
        }
        
        return ans;
    }
};