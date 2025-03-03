//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        map<int,int> map;
        
        int start = 0;
        int maxLen = 0;
        
        int left = 0;
        for(int right = 0; right < arr.size(); right++) {
            map[arr[right]]++;
            
            while (left <= right && prev(map.end())->first - map.begin()->first > x) {
                map[arr[left]]--;
                if (map[arr[left]] == 0) {
                    map.erase(arr[left]);
                }
                left++;
            }
            
            if(maxLen < right - left + 1) {
                start = left;
                maxLen = right - left + 1;
            }
        }
        
        vector<int> ans(arr.begin() + start, arr.begin() + start + maxLen);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends