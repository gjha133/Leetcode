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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap; 
        for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }
   TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap) {
        if(preStart > preEnd or inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];      // inRoot givevs the index of root in Inorder
        int numsLeft = inRoot - inStart;    // Numbers from starting to before root are part of left subtree

       // Preorder -> [Root | Left | Right]...... We start from root + 1 and root + left for end
       // Inorder  -> [Left | Root | Right]...... We start from starting and go till root - 1
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
       
       // Preorder -> [Root | Left | Right]...... We start from root + left + 1 for start and go till end for end
       // Inorder  -> [Left | Root | Right]...... We start from root + 1 and go till end
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};