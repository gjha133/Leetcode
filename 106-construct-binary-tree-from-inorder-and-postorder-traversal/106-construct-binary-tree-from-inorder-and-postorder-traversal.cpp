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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> map;
        for(int i=0; i<inorder.size(); i++) map[inorder[i]] = i;
        TreeNode * root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, map);
        return root;
    }
    
    TreeNode* buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &map)
    {
        if(inStart > inEnd or postStart > postEnd) return NULL;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        
        int rootIndex = map[postorder[postEnd]];        // Taking root index in INORDER from last element in postorder 
        int numsLeft = rootIndex - inStart;             // Numbers from starting to before root are part of left subtree
        
        // Inorder   -> [Left | Root | Right]...... We start from start and go till rootIndex - 1
        // Postorder -> [Left | Right | Root]...... We start from start and go till start + left numbers - 1     
        root->left = buildTree(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + numsLeft - 1, map);
        
        // Inorder   -> [Left | Root | Right]...... We start from start and go till rootIndex - 1
        // Postorder -> [Left | Right | Root]...... We start from start and go till start + left numbers - 1        
        root->right = buildTree(inorder, rootIndex + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, map);
        return root;
    }
};