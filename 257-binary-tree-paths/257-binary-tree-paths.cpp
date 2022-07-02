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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        string curr = "";
        
        paths(root, answer, curr);
        return answer;
    }
    
private:
    void paths(TreeNode* root, vector<string> &answer, string curr) {
        if(!root) return;
        if(root->left or root->right) curr += (to_string(root->val) + "->");
        else
        {
            curr += to_string(root->val);
            answer.push_back(curr);
        }
        
        paths(root->left, answer, curr);
        paths(root->right, answer, curr);
    }
};