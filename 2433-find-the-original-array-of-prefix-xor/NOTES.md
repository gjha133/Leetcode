XOR Property
To solve this problem we should know a basic propery:-
It says if a^b = c then
b^c = a
a^c = b
​
For Example:
5^2 = 7
2^7 = 5
5^7 = 2
​
Solution
```
​
We know pref[0] will be always equal to ans[0]  only because that is only one element.
​
So now, we have
​
pref[1] = ans[0]^ans[1], So by using above property
ans[1] = ans[0]^pref[1]
So we get ans[1]
Now again
pref[2] = ans[0]^ans[1]^ans[2], So
ans[0]^ans[1] = a, consider this as a single value then
ans[2] = ans[0]^ans[1]^pref[2]
​
So we get ans[2] now
​
Now again
pref[3] = ans[0]^ans[1]^ans[2]^ans[3]
ans[3] = ans[0]^ans[1]^ans[2]^pref[3]
​
So we get ans[3]
In this way we can get entire array.
```