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
    unordered_map<long ,int> prefixCount;
    int count{0};
public:
    void dfs(TreeNode* root, int targetSum, long partialSum){
        if(!root)return;
        
        partialSum += root->val;
        count += prefixCount[ partialSum -  targetSum];
        
        prefixCount[partialSum]++;
        
        if(root->left){
            dfs(root->left, targetSum , partialSum);
        }
        if(root->right){
           dfs(root->right, targetSum, partialSum); 
        }
        prefixCount[partialSum]--; // backtrack
        
    }
        
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        
        prefixCount[0] = 1;
        dfs(root, targetSum, 0);
        
        return count;
    }
};