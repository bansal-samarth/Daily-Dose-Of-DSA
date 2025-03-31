//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxPartitions(string s) {
        int count=0;
        
        vector<int> lastIndex(26);
        
        for(int i=0;i<s.length();i++){
            int pos=s[i]-'a';
            
            lastIndex[pos]=i;
        }
        
        int range=0;
        
        for(int i=0;i<s.length();i++){
            range=max(range, lastIndex[s[i]-'a']);
            
            if(range==i) count++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends