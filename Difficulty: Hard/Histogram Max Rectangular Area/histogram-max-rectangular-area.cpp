//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        stack<int> st;
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if(st.empty()) left[i] = 0;
            else left[i] = st.top() + 1;
            
            st.push(i);
        }
        
        while(st.size()) st.pop();
        
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if(st.empty()) right[i] = n-1;
            else right[i] = st.top() - 1;
            
            st.push(i);
        }
        
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int len = arr[i];
            int wid = right[i] - left[i] + 1;
            
            maxArea = max(maxArea, len * wid);
        }
        
        return maxArea;
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
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends