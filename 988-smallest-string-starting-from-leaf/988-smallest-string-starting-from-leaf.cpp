/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
public:
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        string ans = "~";
        helper(root, s, ans);
        return ans;
    }
    
private:
    void helper(TreeNode* root, string &s, string &ans)
    {
        if(!root) return;
        
        s.push_back(root->val + 'a');     // if root->val = 1 then 1 + 'a' = b
        
        if(root->left == root->right)
        {
			 string str=s;
			 reverse(str.begin(),str.end());
			 if(ans.empty() or str<ans) ans=str;
		}
		helper(root->left,s, ans);
		helper(root->right,s, ans);
		s.pop_back();
    }
};