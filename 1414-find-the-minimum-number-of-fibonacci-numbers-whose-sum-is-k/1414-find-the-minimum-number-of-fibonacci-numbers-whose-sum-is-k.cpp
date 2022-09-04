class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = generateFib(k);
        int end = fib.size() - 1, ans = 0;
        while(k)
        {
            if(fib[end] <= k) 
            {
                k -= fib[end];
                ans++;
            }
            end--;
        }
        
        return ans;
    }
    
    vector<int> generateFib(int k)
    {
        vector<int> fib;
        int prev = 1, prev1 = 1;
        fib.push_back(prev);
        fib.push_back(prev1);
        
        while(prev < k)
        {
            int cur = prev + prev1;
            fib.push_back(cur);
            prev1 = prev;
            prev = cur;
        }
        
        return fib;
    }
};