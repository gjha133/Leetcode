Very nicely explained intuition
https://www.youtube.com/watch?v=OKcrLfR-8mE
​
```
//Questions to ask the interviewer -
​
//1. So you said k is an integer? Can the k be equal to 0? Can it be n-ve?
// ANS - k can be positive, zero or negative - consider all cases !
​
// Positive case - [23, 2, 4, 6, 7],  k=6; ANS = true
//Negative Case - [23,2,4,6,7], k= -6; ANS = true (Since n=-1 and -1*-6=6)
//Zero Case - [0,0], k=0; ANS = true
​
//2. 'n' can be anything right? positive, negative and zero
​
//Explanation of algorithm to interviewer -
​
//A proof sketch:
// Suppose sum_i represents the running sum starting from index 0 and ending at i
// once we find a mod that has been seen, say modk, we have:
​
// current one: sum_i = m*k + modk
// previous one: sum_j = n*k + modk
// Thus,
// sum_i - sum_j = (m - n) *k
​
//so if two runningSum mod k have the same values, then when they are subtracted, they are bound to be multiples of k
```