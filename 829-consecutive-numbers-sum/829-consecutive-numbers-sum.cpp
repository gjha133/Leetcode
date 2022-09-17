class Solution {
public:
    int consecutiveNumbersSum(int N) {
        long long int count = 0; 
        for (long long int k = 0; k*(k+1)/2 < N ;k++) 
        {
            double a = ((double) N)/((double) k + 1) - (double) k/2;
            if (a - (int) a == 0) {
                count += 1;
            }
        }
        return count; 
    }
};