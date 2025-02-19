//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> maxi;
        priority_queue<int, vector<int>, greater<int>> mini;
        
        vector<double> ans;
        
        for(int num : arr) {
            if(maxi.size() == 0 || num <= maxi.top())
                maxi.push(num);
            else
                mini.push(num);
            
            if(maxi.size() > mini.size() + 1) {
                mini.push(maxi.top());
                maxi.pop();
            } else if(maxi.size() < mini.size()) {
                maxi.push(mini.top());
                mini.pop();
            }
            
            if((maxi.size() + mini.size()) % 2)
                ans.push_back(maxi.top() * 1.0);
            else
                ans.push_back((double)(maxi.top() + mini.top()) / 2.0);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends