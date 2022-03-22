Explanation :-
https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/discuss/1871662/JavaC%2B%2B-Easiest-Possible-Exaplained!!
​
```
n = 5 and k = 73
Declaring an array with all a's equal to 5
ans = [a, a, a, a, a];
k = k - n = 73 - 5 = 68
k = 68
​
[a, a, a, a, z]
n = 4 ---> min(25,68) --> k = 68 - 25 = 43
​
[a, a, a, z, z]
n = 3 ---> min(25, 43) --> k = 43 - 25 = 18
​
[a, a, s, z, z]
n = 2 ---> min(25, 18) --> k = 18 - 18 = 0
​
k == 0. Exit out of while loop.
ans->>
[a, a, s, z, z]
​
```
​