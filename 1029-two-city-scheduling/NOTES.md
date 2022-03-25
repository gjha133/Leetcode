In total there are 2n people.
We have to send n people to A city and n people to B city.
Find the min cost to send every person to city A and city B.
​
​
Approach:-
Let us assume first that we schedule for all of them to go to city A.
Compute the cost of doing that.
```
costs = [ [259,770] , [448,54] , [926,667] , [184,139] , [840,118] , [577,469] ]
​
So, costA = 259 + 448 + 926 + 184 + 840 + 577 = 3234
​
```
​
Now we have assumed that we scheduled 2n people to city A.
But we have to send n people to city B also.
​
So now we compute the difference of cost of sending a person  to city B instead of city A.
​
```
diff = [ 511, -394, -259, -45, -722, -112 ]
​
if diff[i] is positive, it means that it is not profitable to send person to city B.
if diff[i] is negative, it means that it is profitable to send person to city B.
​
```
​
If we sort diff, we can see the max profit in order.
```
diff = [ -722, -394, -259, -112, -45, 511 ]
​
```
We take n max profits and send the people to city B not city A.
In this case,
​
```
profits = -722 + (-394) + (-259) = -1375
Total cost,
costA = 3234 + (-1375) = 1859