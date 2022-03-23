Approach
https://leetcode.com/problems/broken-calculator/discuss/1874813/JavaC%2B%2B-Recursive-and-Iterative-Solution
​
Instead of changing startvalue every iteration we change the target and try to make target equal to startvalue.
the multiply is changed to division
and the subtraction is changed to addition
Here we divide the target by 2 until it is less than startvalue and then simply count the addition operations to make it equal to startvalue.
If target is even we divide it by 2.
And if target is odd we simply add 1 to make it even.
For Eg:-
​
```
count = 0;
startValue           target
10                    100
​
1. target = 100/2 = 50.           count = 1;
2. target = 50/2 = 25.             count = 2;
3. target = 25+1 = 26.            count = 3;
4. target = 26/2 = 13.             count = 4;
5. target = 13+1 =14.             count = 5;
6. target = 14/2 = 7.               count = 6;
​
Now target is less than startValue (7 < 10)
We simply now add 1 (startValue - target) times to make it equal to startValue.
ans = count + startValue - target;
ans = 6 + 10 - 7 = 9.
```
​
​
​
​
​