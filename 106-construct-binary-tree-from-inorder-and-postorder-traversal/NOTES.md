**Also good:-**
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/1589310/C%2B%2BPython-2-Simple-Solutions-w-Images-and-Detailed-Explanation-or-Recursion-%2B-Hashmap
​
**Another One:-**
The Idea is As They Given us Inorder and Postorder
​
as we Know Inorder Fallow --> Left_subtree => Root_Node => Right_subtree Traverse
ans   Postorder Fallow --> Left_subtree => Right_subtree =>Root_Nodetraverse
using Postorder_array We can Find Root_Node Which always lay in Postorder_array last Possition
After Finding That Root_Node ,First we are going to divide Inorder_array Into Two Part and Postorder Array
into Two part .
```
Then We are going to use Both of the arrays left part to Figur Out Left_subtree
and Both of the arraysRigth Part to Figur out Right_subtree
​
We are going to recursively do so until One Of the array dose not got empty
​
```
Let's take an Example
```
inorder   = [4 2 5 1 6 3 7]
postorder = [4 5 2 6 7 3 1]
​
So root would be 1 here and Left array which lay left of 1 is [4 2 5] and Right of 1 is [6 3 7]
so left_inorder_array =  [4 2 5] and right_inorder_arry = [6 3 7]
​
using 6 [ which is just rigth of 1] we are going to devide Postorder_array into two part