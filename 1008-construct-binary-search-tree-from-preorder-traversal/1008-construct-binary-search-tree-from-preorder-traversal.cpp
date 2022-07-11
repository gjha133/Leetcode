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
    // Method 1
    // Sort preorder to get the inorder, and then build a unique bst
    // T.C O(N + logn) and S.C O(N)
    
    //Method 2 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        int upperBound = INT_MAX;
        return buildBST(preorder, index, upperBound);
    }
    
    TreeNode* buildBST(vector<int> &preorder, int &index, int upperBound)
    {
        if(preorder.size() == index or preorder[index] > upperBound) return NULL;
        
        TreeNode* root = new TreeNode(preorder[index++]);
        
        root->left = buildBST(preorder, index, root->val);
        root->right = buildBST(preorder, index, upperBound);
        
        return root;
    }
};