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
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> nodes;
            while(n--)
            {
                auto node = q.front();
                nodes.push_back(node->val);
                q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            ans += swaps(nodes);
        }
        
        return ans;
    }
    
    int swaps(vector<int>& nums)
    {
        int count = 0;
        map<int, int> mp;
        vector<int> sorted;
        
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]] = i;
            sorted.push_back(nums[i]);
        }
        
        sort(sorted.begin(), sorted.end());
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != sorted[i])
            {
                nums[mp[sorted[i]]] = nums[i];
                mp[nums[i]] = mp[sorted[i]];
                mp[sorted[i]] = i;
                nums[i] = sorted[i];
                count++;
            }
        }
        
        return count;
    }
};