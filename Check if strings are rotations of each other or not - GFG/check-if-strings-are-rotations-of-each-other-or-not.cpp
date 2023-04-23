//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string A,string B)
    {
        // Your code here
        if(A.size() != B.size()) return false;
        if(A == B) return true;
        
        int len = B.size();
        while(len--)
        {
            if(A == B) return true;
            A = A.substr(1) + A[0];     // one shift on A
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends