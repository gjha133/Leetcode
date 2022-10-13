class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int num : nums) arr.push_back(to_string(num));
        
        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });  // lambda function
        
        //for(auto str : arr) cout << i << " ";
        
        string res;
        for(string s : arr) res += s;
        
        while(res[0]=='0' && res.length()>1) res.erase(0,1);
        
        return res;
    }
};