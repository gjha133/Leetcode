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

int ans;
struct custom {
    bool bst;
    int mx;
    int mn;
    int ms;
    
    custom() {
        bst = true;
        mx = INT_MIN;
        mn = INT_MAX;
        ms = 0;
    }
};

class Solution {
public:
    
    custom maxSum(TreeNode* root) {
        if(!root) return  custom();
        
        custom obj;
        custom left = maxSum(root->left);
        custom right = maxSum(root->right);
        
        if(left.bst == true and right.bst == true and root->val > left.mx and root->val < right.mn)
        {
            obj.bst = true;
            obj.ms += left.ms + right.ms + root->val;
            obj.mn = min(root->val, left.mn);
            obj.mx = max(root->val, right.mx);
        }
        else
        {
            obj.bst = false;
            obj.ms = max(left.ms, right.ms);
        }
        
        ans = max(ans, obj.ms);
        return obj;
    }
    
    int maxSumBST(TreeNode* root) {
        ans = 0;
        maxSum(root);
        return ans;
    }
};