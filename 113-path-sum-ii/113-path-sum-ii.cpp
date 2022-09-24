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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answer;
        vector<int> path;
        allPaths(root, targetSum, answer, path);
        return answer;
    }
    
private:
    void allPaths(TreeNode* root, int targetSum, vector<vector<int>> &answer, vector<int> path) {
        if(!root) return;
        
        //Adding root->val to vector
        path.push_back(root->val);
        targetSum -= root->val;
        if(!root->left and !root->right and !targetSum) answer.push_back(path);
        else
        {
            allPaths(root->left, targetSum, answer, path);
            allPaths(root->right, targetSum, answer, path);
        }
        
        //Remove from vector if there is no path through that node
        path.pop_back();    
    }
};