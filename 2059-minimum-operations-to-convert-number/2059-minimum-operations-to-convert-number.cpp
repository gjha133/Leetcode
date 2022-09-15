class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<int> visited(1001, 0);
        queue<int> q;
        q.push(start);
        int ans = 0;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                int x = q.front();
                q.pop();
                if(x == goal) return ans;
                if(x > 1000 or x < 0 or visited[x]) continue;
                visited[x] = 1;
                
                for(auto num : nums)
                {
                    q.push(x + num);
                    q.push(x - num);
                    q.push(x ^ num);
                }
            }
            ans++;
        }
        
        return -1;
    }
};