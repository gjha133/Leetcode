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
        int ans = 0;
        f(root, INT_MIN, ans);
        return ans;
    }
    
    void f(TreeNode* root, int max, int &ans)
    {
        if(root == NULL) return;
        if(root->val >= max) 
        {
            max = root->val;
            ans++;
        }
        
        f(root->left, max, ans);
        f(root->right, max, ans);        
    }
};