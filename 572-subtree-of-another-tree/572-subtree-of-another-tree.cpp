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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(!subRoot) return true;
        
        if(sameTree(root, subRoot)) return true;
        
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
    
private: 
    bool sameTree(TreeNode* p, TreeNode* q)
    {
        // If p (null) and q (!null) and vice versa, it will return false
        // But is both p and q are null then it will return true
        if(!p or !q) return p == q;
        return p->val == q->val and sameTree(p->left, q->left) and sameTree(p->right, q->right);
    }
};