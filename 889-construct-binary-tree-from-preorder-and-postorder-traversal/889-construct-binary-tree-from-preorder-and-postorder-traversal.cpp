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
using N = TreeNode;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postMap;
        int n = preorder.size();
        for(int i=0; i<n; i++) postMap[postorder[i]] = i;
        
        return buildTree(preorder, 0, n-1, postorder, 0, n-1, postMap);
    }
    
private:
    N* buildTree(vector<int> &pre, int preS, int preE, vector<int> &post, int postS, int postE, unordered_map<int, int> &postMap)
    {
        if(preS > preE or postS > postE) return NULL;
        
        // Making new root node with first element of preorder
        N* root = new N(pre[preS]);
        if(preS == preE) return root;
        
        int leftRoot_Pre =  preS + 1;
        // Finding the root index of left subtree in postorder vector
        int leftRoot_Post = postMap[pre[leftRoot_Pre]];
        int numLeft = leftRoot_Post - postS;
        
        root->left = buildTree(pre, leftRoot_Pre, leftRoot_Pre + numLeft, post, postS, leftRoot_Post, postMap);
        root->right = buildTree(pre, leftRoot_Pre + numLeft + 1, preE, post, leftRoot_Post + 1, postE, postMap);
        
        return root;
    }
};