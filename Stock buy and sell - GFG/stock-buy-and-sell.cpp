//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int arr[], int n) {
    // code here
    int ct=0;
    int x=0;
    for(int i=0;i<n-1;i++){
        if(i==n-1){
            break;
        }
        else if(arr[i+1]>arr[i] && ct==0){
            ct++;
            x++;
            cout<<"("<<i<<" ";
        }
        else if(arr[i+1]<arr[i] &&  ct==1){
            ct--;
            cout<<i<<") ";
            
        }
         
    }
    
    if(ct>0){
        cout<<n-1<<")";
    }
    if(x==0){
        cout<<"No Profit";
    }
    cout<<endl;
}