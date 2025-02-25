//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int N){
        if(N <= 6) return N;
        
        vector<int> dp(N+1, 0);
        for(int i = 0; i <= 6; i++) {
            dp[i] = i;
        }
        
        for(int i = 7; i <= N; i++) {
            for(int j = i-3; j >= 1; j--) {
                dp[i] = max(dp[i], dp[j] * (i-j-1));
            }
        }
        
        return dp[N];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends