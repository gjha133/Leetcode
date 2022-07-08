/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        while (true) {
            if (p->val  < node->val and q->val < node->val) node = node->left; //both values are on the left of current node
            else if (p->val > node->val and q->val > node->val) node = node->right; //both values are on right of current node
            else break;            
        }
        
        return node;
    }
};