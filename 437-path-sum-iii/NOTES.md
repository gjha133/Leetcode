/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
int pathSum(TreeNode* root, int targetSum) {
unordered_map<int,int> map;
int count = 0;
countPaths(root, targetSum, 0, map, count);
return count;
}
private:
void countPaths(TreeNode* root, int targetSum, int currentSum, unordered_map<int,int> &map, int &count)
{
if(!root) return;
currentSum += root->val;
if(currentSum == targetSum) count++;
if(map.find(currentSum-targetSum) != map.end()) count += map[currentSum-targetSum];
map[currentSum]++;
countPaths(root->left, targetSum, currentSum, map, count);
countPaths(root->right, targetSum, currentSum, map, count);
map[currentSum]--;
}
};