class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left = 0, n = colors.size(), right = n - 1;
        while (colors[left] == colors[n-1]) 
            left++;
        while (colors[right] == colors[0]) 
            right--;
        
        return max(right, n - 1 - left);
    }
};