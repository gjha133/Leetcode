class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = generateFib(k);
        int n = fib.size(), end = n - 1;
        int ans = 0;
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
        fib.push_back(1);
        fib.push_back(1);
        
        int size = fib.size();
        while(fib[size - 1] < k)
        {
            fib.push_back(fib[size-1] + fib[size-2]);
            size++;
        }
        
        return fib;
    }
};