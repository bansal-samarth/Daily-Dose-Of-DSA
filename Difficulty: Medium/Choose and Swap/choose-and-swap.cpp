//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string chooseandswap(string str) {
        vector<int> first(26, -1);
        int k = 0;
        for(int i = 0; i < str.size(); i++) {
            char ch = str[i];
            if(first[ch-'a'] == -1)
                first[ch-'a'] = k++;
        }
        
        char a = '#', b = '#';
        int curr = 0;
        for(int i = 0; i < 26; i++) {
            if(first[i] == -1)
                continue;
            
            if(first[i] != curr) {
                a = i + 'a';
                while(i < 26 && first[i] != curr)
                    i++;
                
                b = i + 'a';
                break;
            }
            
            curr++;
        }
        
        if(a == '#' || b == '#') return str;
        
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == a)
                str[i] = b;
            else if(str[i] == b)
                str[i] = a;
        }
        
        return str;
    }
};


//{ Driver Code Starts.

int main() {
    Solution obj;
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << obj.chooseandswap(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends