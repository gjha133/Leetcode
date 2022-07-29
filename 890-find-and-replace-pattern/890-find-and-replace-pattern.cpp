class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        // For every word in words, if word and pattern match then store in vector
        for(auto& word : words) 
            if(match(word, pattern)) 
                ans.push_back(word);
        
        return ans;
    }
    
    bool match(string &word, string &pattern)
    {
        unordered_map<char, char> word_pattern, pattern_word;
        for(int i=0; i<size(word); i++)
        {
                //If mapping in word_pattern is there for word[i] and it is not equal to pattern[i] and vice versa
            if(   (word_pattern.count(word[i]) and word_pattern[word[i]] != pattern[i]) 
                                                or 
                 (pattern_word.count(pattern[i]) and pattern_word[pattern[i]] != word[i]) 
              )
            {
                   return false;
            }
            else
            {
                word_pattern[word[i]] = pattern[i];
                pattern_word[pattern[i]] = word[i];
            }
        }
               
        return true;
    }
};