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

    bool flipEquiv(TreeNode* p, TreeNode* q) {
        // If both are null, true
        if (p == NULL && q == NULL) return true;
        // One of p and q is null, false
        if (q == NULL || p == NULL) return false;
        // If node values dont match, false
        if (p->val != q->val) return false;
        
        return (flipEquiv(p->left,q->left) and flipEquiv(p->right,q->right)) 
                                            or  
                (flipEquiv(p->left,q->right) and flipEquiv(p->right,q->left));
    }
};