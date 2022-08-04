int ans = 0; // to store the number of our subarrays having sum as 'k'
for(int i = 0; i < n; i++) // traverse from the prefix array
{
if(prefix[i] == k) // if it already becomes equal to k, then increment ans
ans++;
// now, as we discussed find whether (prefix[i] - k) present in map or not
if(mp.find(prefix[i] - k) != mp.end())
{
ans += mp[prefix[i] - k]; // if yes, then add it our answer
}
mp[prefix[i]]++; // put prefix sum into our map
}
return ans; // and at last, return our answer
}
};
```
​
​