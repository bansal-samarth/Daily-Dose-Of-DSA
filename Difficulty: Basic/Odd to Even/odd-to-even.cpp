//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string makeEven(string s) {
        
        string ans = s;
        
        int n = s.size();
        int last = s[n - 1];
        
        int pos = -1;
        
        for(int i = 0; i < n; i++) {
            int digit = s[i];
            
            if(digit % 2)
                continue;
            
            pos = i;
            
            if(digit < last)
                break;
        }
        
        if(pos != -1)
            swap(ans[pos], ans[n-1]);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    Solution ob;
	    cout<<ob.makeEven(str)<<endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends