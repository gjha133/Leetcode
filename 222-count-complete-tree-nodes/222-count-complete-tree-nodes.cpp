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
    // Time Complexity - O((logn)^2)
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int leftH = leftheight(root);
        int rightH = rightheight(root);
        
        if(leftH == rightH) return (1<<leftH) - 1;     // 1<<left ---> 1*2^left
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
private:    
    int leftheight(TreeNode* root)
    {
        int h = 0;
        while(root)
        {
            h++;
            root = root->left;
        }
        
        return h;
    }
    
    int rightheight(TreeNode* root)
    {
        int h=0;
        while(root)
        {
            h++;
            root = root->right;
        }
        
        return h;
    }
};