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
    int goodNodes(TreeNode* root) {
        return f(root, root->val);
    }
    
    int f(TreeNode* root, int max)
    {
        if(root == NULL) return 0;
        int ans = 0;
        if(root->val >= max) 
        {
            max = root->val;
            ans++;
        }
        
        int left = f(root->left, max);
        int right = f(root->right, max); 
        
        return ans + left + right;
    }
};