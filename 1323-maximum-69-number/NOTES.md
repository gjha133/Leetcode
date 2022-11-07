```
class Solution {
public:
int maximum69Number (int num) {
int n = num;
int PVnextdigit = 1;            // From right to left
int PVsixchange = 0;            // PV -> Place Value
while(n > 0)
{
int lastDigit = n % 10;
if(lastDigit == 6) PVsixchange = PVnextdigit;
PVnextdigit *= 10;
n /= 10;
}
// Now we have the place value of leftmost 6 digit
// We will change the 6 digit with 9 using the formula
num += PVsixchange*3;
return num;
}
};
```
​
num = 969
PVnextdigit = 1, n = 969, PVsixchange = 0
​
1. digit = 9..........PVsixchange = 0..........PVnextdigit = 10........n = 96
2. digit = 6..........PVsixchange = 10........PVnextdigit = 100......n = 9
3. digit = 9..........PVsixchange = 10........PVnextdigit = 1000....n = 0
num = 969 + (10x3) = 969 + 30 = 999
​
​
​
```
class Solution {
public:
int maximum69Number (int num) {
string s_num = to_string(num);
for (auto &c : s_num) {
if (c == '6') {
c = '9';
break;
}
}
return stoi(s_num);
/*
for (auto c : s) //*distinct object* (think: a copy usually)
​
for (auto& c : s) //reference into the string (can modify string)
Short: use auto& when you need to modify the contents.
*/
}