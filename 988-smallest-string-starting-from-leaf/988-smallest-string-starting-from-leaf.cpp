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
    string ans;
public:
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        helper(root, s);
        return ans;
    }
    
private:
    void helper(TreeNode* root, string &s)
    {
        if(!root) return;
        s.push_back(root->val + 'a');
        if(root->left==root->right){
			 string str=s;
			 reverse(str.begin(),str.end());
			 if(ans.empty() || str<ans)
				 ans=str;
		}
		helper(root->left,s);
		helper(root->right,s);
		s.pop_back();
    }
};