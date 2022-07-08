https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/discuss/1426993/Verify-Preorder-Serialization-of-a-Binary-Tree-or-How-Many-Slots-Are-Available
​
Every non-null node will give me 2 slots but will also consume 1 (itself).
So for non-null node, node count will increase by 1.
Every null node will consume 1 slot and wont give any new slot.
So for null node, node count will decrease by 1.