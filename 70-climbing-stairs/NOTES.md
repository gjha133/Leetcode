Approach 1 : (Recursion)
​
Recursion is a programming technique using function or algorithm which calls itself directly or indirectly until a suitable condition is met. In this method, we repeatedly call the function within the same function, and it has a base case and a recursive condition.
​
It gives us Time Limit Exceeded (TLE)
```
class Solution {
public:
int climbStairs(int n) {
if(n<0) return 0;
if(n==0 or n==1) return 1;
return climbStairs(n-1)+climbStairs(n-2);
}
};
```
Approach 2 : (DP - Memoization / Top Down)
​
Memoization is a technique for improving the performance of recursive algorithms. It involves rewriting the recursive algorithm so that as answers to problems are found, they are stored in an array. Recursive calls can look up results in the array rather than having to recalculate them.
​
We start our journey from the top most destination state and compute its answer by taking in count the values of states that can reach the destination state, till we reach the bottom-most base state. Hence, it is also called as Top-Down Approach
​
```
class Solution {
public: