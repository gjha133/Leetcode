class Solution {
public:
    bool isAnagram(string a, string b) {
        if(a.size() != b.size()) return false;
        int freq[256] = {0};
        for(int i=0; i<a.size(); i++)
        {
            freq[a[i]]++;
            freq[b[i]]--;
        }      
        
        for(int count : freq) if(count) return false;
        
        return true;
    }
};