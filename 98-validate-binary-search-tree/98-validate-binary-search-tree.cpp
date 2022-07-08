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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long min, long max)
    {
        if(!root) return true;
        //If root's value is out of range, false
        if(root->val >= max or root->val <= min) return false;
        // If we go left then root->value becomes the max
        // If we go right then root->value becmoes the min
        return isValidBST(root->left, min, root->val) and isValidBST(root->right, root->val, max);        
    }
};