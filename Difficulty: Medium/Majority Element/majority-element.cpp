//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {

        int ans = -1;
        int count = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            if(ans == -1) {
                ans = arr[i];
                count = 1;
            }
            else if(arr[i] == ans)
                count++;
            else
                count--;
            
            if(count == 0) {
                ans = -1;
                count = 0;
            }
        }
        
        if(ans == -1) return -1;
        
        int freq  = 0;
       
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == ans){
                freq++;
            }
        }
        
        if(freq > arr.size()/2 )
            return ans;
      
      return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends