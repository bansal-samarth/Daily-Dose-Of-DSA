//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N) {
        vector<int> currency = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> coins;
        
        for(int i = 0; i < currency.size(); i++) {
            while(currency[i] <= N) {
                N -= currency[i];
                coins.push_back(currency[i]);
            }
        }
        
        return coins;
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
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends