**Optimised Approach:-**
Kadane's Algorithm
​
```
nums = [ -2 , 1 , -3 , 4 , -1 , 2 , 1 , -5 , 4 ]
​
sum = 0;        maxi = - inf;
​
i = 0;      num = -2;      sum = -2;      maxi = -2;      sum = 0;
i = 1;      num = 1;       sum = 1;        maxi = 1;       sum = 1;
i = 2;      num = -3;      sum = -2;      maxi = 1;       sum = 0;
i = 3;      num = 4;       sum = 4;        maxi = 4;       sum = 4;
i = 4;      num = -1;      sum = 3;       maxi = 4;       sum = 3;
i = 5;      num = 2;       sum = 5;        maxi = 5;       sum = 5;
i = 6;      num = 1;       sum = 6;        maxi = 6;       sum = 6;
i = 7;      num = -5;      sum = 1;        maxi = 6;       sum = 1;
i = 8;      num = 4;       sum = 4;        maxi = 6;       sum = 4;
​
​
maxi = 6;
Max Subarray = [4, -1, 2, 1]
```
​
​
​