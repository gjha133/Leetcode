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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        findLeaf1(root1, leaf1);
        vector<int> leaf2;
        findLeaf2(root2, leaf2);
        
        return leaf1 == leaf2;
        
    }
    
    void findLeaf1(TreeNode* &root1, vector<int> &leaf1)
    {
        if(!root1->left and !root1->right) {leaf1.push_back(root1->val); return;}
        if(root1->left) findLeaf1(root1->left, leaf1);
        if(root1->right) findLeaf1(root1->right, leaf1);        
    }
    void findLeaf2(TreeNode* &root2, vector<int> &leaf2)
    {
        if(!root2->left and !root2->right) {leaf2.push_back(root2->val); return;}
        if(root2->left) findLeaf2(root2->left, leaf2);
        if(root2->right) findLeaf2(root2->right, leaf2);        
    }
};

