class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> set;
        for(auto w : words)
        {
            string x = "";
            for(char c : w)
            {
                x += morse(c);
            }
            set.insert(x);
        }
        
        return set.size();
    }
    
    string morse(char c)
    {
        string code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",
                          ".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        return code[c - 'a'];
    }
};