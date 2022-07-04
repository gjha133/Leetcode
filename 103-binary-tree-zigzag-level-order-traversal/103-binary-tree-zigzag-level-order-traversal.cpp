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
    using N = TreeNode;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigZag;
        if(!root) return zigZag;
        
        stack<N*> s1;
        stack<N*> s2;
        s1.push(root);
        
        while(!s1.empty() or !s2.empty())
        {
            vector<int> left2right;
            vector<int> right2left;
            
            while(!s1.empty())
            {
                auto node = s1.top();
                s1.pop();
                left2right.push_back(node->val);
                if(node->left) s2.push(node->left);
                if(node->right) s2.push(node->right);
            }
            
            if(left2right.size() > 0) zigZag.push_back(left2right);
            
            
            while(!s2.empty())
            {
                auto node = s2.top();
                s2.pop();
                right2left.push_back(node->val);
                if(node->right) s1.push(node->right);
                if(node->left) s1.push(node->left);
                
            }
            
            if(right2left.size() > 0) zigZag.push_back(right2left);
        }
        
        
        return zigZag;
    }
};