We can see that the number of coins required for the kth row will be equal to 1 + 2 + 3 + ... + k = k * (k + 1) / 2.
​
We can solve this problem using binary search over the possible answer range. But how do we get that we could solve this problem using binary search?
​
We can observe that our answer range is sorted from l = 0 to r = n.
We need to find some value rows = (l+r)/2 such that the coins needed, coinsNeeded = row*(row + 1) / 2 to form rows is less than or equal to available coins n.
If coinsNeeded > n, meaning we have less coins than required to form rows, we know that any number of row greater than rows is impossible to form with given number of coins, so we can safely eliminate the half greater rows by doing r = rows-1.
If coinsNeeded <= n, meaning we have coins greater or equal to coinsNeeded to form rows, then the current number of rows is formable. We mark this as a possible answer and search if a higher number of rows can be formed by doing l = rows + 1.