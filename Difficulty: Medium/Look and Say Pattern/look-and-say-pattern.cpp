//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        // code here
        string res="1", temp="";
        for(int i=1; i<n; i++){
            int count=1;
            for(int j=0; j<res.size(); j++){
                while(res[j]==res[j+1]){
                    count++;
                    j++;
                }
                temp = temp+to_string(count)+res[j];
                count=1;
            }
            res=temp;
            temp="";
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends