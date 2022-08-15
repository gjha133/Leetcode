class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if (n < 10) return {};
        
        //to get unique string and not repetitive
        unordered_map<string, int> map;
        
        vector<string> result;
        /*
        substr(position, length): 
        say length of input string is 12 
        so loop run till 12-9= 3

        substr function will pick input string's characters 
        i=0 -> 0 to 9 (as indexing start from 0)
        i=1 -> 1 to 10
        i=2 -> 2 to 11

        hence covered whole input string length and we are doing this in hashmap so frequency is being taken care of simultaneously
        */
        for (int i = 0; i < n-9; i++) 
            map[s.substr(i, 10)]++;            

        //if frequency is greater than 1 push the string in result vector
        for (auto it : map)
            if (it.second > 1) result.push_back(it.first);
                

        return result;
        
    }
};