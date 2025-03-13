//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution {
 public:
    string rec(string& str) {
        int n = str.size();
        string res = "";
        
        int count = 1;
        for(int i = 0; i < n; i++) {
            if(str[i] != str[i+1] || n == i+1) {
                res += to_string(count) + string(1, str[i]);
                count = 1;
            } else
                count++;
        }
        
        return res;
    }
    string lookandsay(int n) {
        
        string ans = "1";
        
        for(int i = 1; i < n; i++) {
            ans = rec(ans);
        }
        
        return ans;
    }   
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends