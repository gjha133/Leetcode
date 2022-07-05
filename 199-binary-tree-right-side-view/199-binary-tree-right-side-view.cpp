/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}vector<int
 * };
 */
class Solution {
public:
     /*vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curNode = nullptr;
        while (!q.empty()){
            int n = q.size();
            while (n--) {
                curNode = q.front();
                q.pop();
                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);
            }
            ans.push_back(curNode->val);
        }
        return ans;
    }
    */
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightview;
        right(root, 0, rightview); 
        return rightview;
    }
    
    void right(TreeNode *node, int level, vector<int> &rightview)
    {
        if(!node) return;
        if(rightview.size() == level) rightview.push_back(node->val);
        right(node->right, level + 1, rightview);
        right(node->left, level + 1, rightview);
    }
    
    
};