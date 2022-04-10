class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> ans;
        int j=-1;
        for(auto s : ops)
        { 
            if(s == "C") {ans.pop_back(); --j;continue;}
            if(s == "D") {ans.push_back(2*ans[j]); ++j;}
            else if(s == "+") {ans.push_back(ans[j] + ans[j-1]); ++j;}
            else {ans.push_back(stoi(s)); ++j;}
        }
        
        return accumulate(ans.begin(), ans.end(), 0);
    }
};