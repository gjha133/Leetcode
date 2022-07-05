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
    int sumNumbers(TreeNode* root) {
        return sumAllLeaf(root, 0);
    }
    
    int sumAllLeaf(TreeNode* root, int sum)
    {
        if(!root) return 0;
        
        sum = sum * 10 + root->val;
        if(!root->left and !root->right) return sum;
        
        int left = sumAllLeaf(root->left, sum);
        int right = sumAllLeaf(root->right, sum);
        
        return left + right;
    }
};