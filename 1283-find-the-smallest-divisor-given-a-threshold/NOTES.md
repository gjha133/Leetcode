Brute Force would be to check for all numbers from 1 to 10^6.
Let's call the process of dividing and summing as divSum.
If divSum(x) = k, then we know that divSum for all numbers > x will be <= k
Hence we can use binary search here.
A binary search can be followed if a certain condition has answer in the form of
[ TT....TFF....F ] or [ FF....FTT...T ]
Here our condition is (divSum(x) <= k) and it's answer will be [ FF....FTT... T]
Now we just need to find the first T.