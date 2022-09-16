class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int cnt=0,i=1;
        while(n>0)
        {
            n-=i;
            if(n%i==0) cnt++;
            i++;
        }
        return cnt;
    }
};