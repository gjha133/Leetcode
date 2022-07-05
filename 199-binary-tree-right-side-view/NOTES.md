This solution still traverses all nodes of the tree, like the BFS solution, but BFS needs to maintain a queue buffer to store each level's nodes, while this solution only needs res buffer
In case of queue the space complexity would be O(maxWidth) while here the complexity is O(height_of_tree)
​
**Recursive way using reverse preorder traversal (root->right->left) DFS**
```
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
```
​
**Iterative Way using Queue BFS**
EXPLANATION (Easy)
​
Traverse the whole tree in level order fashion using BFS along with storing the last processed node (here it is stored in curr).
Keep a tag ( here nullptr) at the end of each level to know that a particular level has ended.
Whenever a level ends store the last processed node value to the ans vector.
Return ans.
CODE IMPLEMENTATION
```
vector<int> rightSideView(TreeNode* root) {
vector<int>ans;
if(root==nullptr)
return ans;
queue<TreeNode*>q;
q.push(root); // Initially push the root node
q.push(nullptr); // Then push nullptr, as level=0 contains only the root node
TreeNode* curr;
while(!q.empty()){
if(q.front()!=nullptr){ // if the end of current level is not reached
curr=q.front(); // keep the current node