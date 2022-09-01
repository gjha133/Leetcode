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
    int goodNodes(TreeNode* root) {
        unordered_map<int, int> store;
        int ans = 0;
        f(root, store, ans);
        return ans;
    }
    
    void f(TreeNode* root, unordered_map<int, int>& store, int &ans)
    {
        if(root == NULL) return;
        store[root->val]++;
        bool good = true;
        for(auto it : store)
        {
            if(root->val < it.first) 
            {
                good = false;
                break;
            }                
        }
        
        if(good) ans++;
        
        f(root->left, store, ans);
        f(root->right, store, ans);
        
        store[root->val]--;
        if(store[root->val] == 0) store.erase(root->val);
    }
};