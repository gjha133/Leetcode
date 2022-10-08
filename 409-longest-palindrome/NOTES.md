***idea： count the frequency of each char, the chars appears even times can all be kept, however, the chars appears odd times must remove one char, then the rest instances of that char can be collected for composition. Finally, the middle char can be from OddGroup
Example: "abccccdd",
step 1: count freq of char before clearning:
a:1
b:1
c:4
d:2
​
step 2: perform clearning and prepare for palindrom composition:
a:0
b:0
c:4
d:2
answer = s.size() - 1 - 1
Step 3: make correction, if necessary (i.e., when at least one char shows odd times)
if OddGroup > 0: answer +=1***