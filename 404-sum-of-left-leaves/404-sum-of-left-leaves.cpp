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
    //We will store our total of left leaves here.
    //int total = 0;
    
    void DFS(bool left, TreeNode* current, int &total){
        //If current doesn't exist, return.
        if (current == NULL){
            return;
        }
        //If it is a left leaf add current->val total then return.
        if (left && current->left == NULL && current->right == NULL){
            total += current->val;
            return;
        }
        
        //Run DFS for the children. 
        //left for the current->left is true as it is a left TreeNode* while right is not.
        DFS(true, current->left, total);
        DFS(false, current->right, total);
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int total = 0;
        DFS(false, root, total);
        return total;
    }
    
    /*int sumOfLeftLeaves(TreeNode* root) {
         return dfs(root, false);        
    }
    
private:
    int dfs(TreeNode* root, bool isLeft)
    {
        if(!root) return 0;
        if(!root->left and !root->right) return isLeft ? root->val : 0;
        return dfs(root->left, true) + dfs(root->right, false);
    }*/
};