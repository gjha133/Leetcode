Solution 1: Depth First Search
​
Please note that p and q always exist in the tree.
Since we dfs from the root down to its children, if current root == p or root == q then current root must be their LCA.
If left subtree contains one of descendant (p or q) and right subtree contains the remaining descendant (q or p) then the root is their LCA.
If left subtree contains both p and q then return left as their LCA.
If right subtree contains both p and q then return right as their LCA.
​
​
Better solution for approach 3:
Prerequisite: Iterative Post Order Traversal using single stack
```
class Solution {
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
Deque<TreeNode> st = new ArrayDeque<>();
TreeNode node = root,prev = null;
boolean oneNodeFound = false;
TreeNode lca = null;
while(!st.isEmpty() || node!=null){
while(node!=null){
if(node == p || node == q){
if(oneNodeFound)
return lca;
else{
oneNodeFound = true;
lca = node;
}
}
st.push(node);
node = node.left;
}
node = st.peek();
if(node.right == null || node.right == prev){
st.pop();
if(lca == node)
lca = st.peek();
prev = node;
node = null;
}
else node = node.right;
}
return lca;
}
}
```
​