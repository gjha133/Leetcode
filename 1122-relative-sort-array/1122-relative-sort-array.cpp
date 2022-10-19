class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int, int> mp;        
        for (auto i : arr1) mp[i]++;
        
        int j = 0;
        
        for (auto i : arr2) 
        {
            while(mp[i]-- > 0) arr1[j++] = i;
        }
        for (auto [num, freq] : mp) 
        {
            while(freq-- > 0) arr1[j++] = num;
        }
        
        return arr1;
    }
};