//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        int n = str.size();

        unordered_map<char, int> map;
        
        for(char ch : str) {
            map[ch] = 0;
        }
        
        int dis = map.size();
        map.clear();

        int ans = INT_MAX;
        
        int left = 0;
        for(int right = 0 ; right < n; right++) {
            map[str[right]]++;
            
            while(map.size() == dis) {
                ans = min(ans, right - left + 1);
                
                map[str[left]]--;
                if(map[str[left]] == 0)
                    map.erase(str[left]);
                
                left++;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends