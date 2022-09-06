class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }
        
        int ans = -1;
        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            int size = q.size();
            ans++;
            while(size--)
            {
                int index = q.front();
                q.pop();
                
                if(index - 1 >= 0 and isExist(arr[index-1],mp)) q.push(index - 1);
                
                if(index + 1 < n and isExist(arr[index+1],mp))
                {
                    if(index + 1 == n-1) return ans + 1;
                    else q.push(index + 1);
                }
                
                if(!isExist(arr[index], mp)) continue;
                
                for(auto i : mp[arr[index]])
                {
                    if(i != index)
                    {
                        if(i == n-1) return ans + 1;
                        q.push(i);
                    }
                }
                
                mp.erase(arr[index]);
            }
        }
        
        return ans;
    }
    
    bool isExist(int x , unordered_map<int,vector<int>> &mp){
        if(mp.find(x) == mp.end())
            return false;
        return true;
    }
};