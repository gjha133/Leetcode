class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        
        for(int i = 0; i<k; i++) sum += cardPoints[i];
        int mx = sum;
        for(int i = 0; i<k; i++)
        {
            int ith_element_from_k = cardPoints[k - i - 1];
            int ith_element_from_n = cardPoints[n - i - 1];
            
            sum -= ith_element_from_k;
            sum += ith_element_from_n;
            mx = max(mx, sum);            
        }
        
        return mx;
    }
};