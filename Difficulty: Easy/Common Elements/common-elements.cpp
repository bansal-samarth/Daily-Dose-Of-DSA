//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b) {
        map<int,int> map;
        for(int ele : a)
            map[ele]++;
        
        vector<int> ans;
        
        for(int ele : b)
            if(map[ele]) {
                ans.push_back(ele);
                map[ele]--;
            }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }
        string str1;
        getline(cin, str1);

        stringstream ss1(str1);
        vector<int> b;
        int num1;
        while (ss1 >> num1) {
            b.push_back(num1);
        }
        Solution ob;
        vector<int> result;
        result = ob.commonElements(a, b);
        for (auto i : result) {
            cout << i << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends