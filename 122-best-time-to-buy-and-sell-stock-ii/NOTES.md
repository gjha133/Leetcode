## Recursion :
```
int f(int i, bool canBuy, vector<int>& prices)
{
if(i == prices.size()) return 0;
int profit = 0;
if(canBuy)
{
int Buy = -prices[i] + f(i + 1, false, prices);
int notBuy = 0 + f(i + 1, true, prices);
profit = max(Buy, notBuy);
}
else // Cant Buy->>> Going to Sell
{
int Sell = prices[i] + f(i + 1, true, prices);
int notSell = 0 + f(i + 1, false, prices);
profit = max(Sell, notSell);
}
return profit;
}
```