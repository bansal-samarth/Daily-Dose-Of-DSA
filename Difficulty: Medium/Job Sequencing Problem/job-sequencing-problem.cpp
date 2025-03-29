//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();
        
        vector<pair<int,int>> vec;
        
        for(int i = 0; i < n; i++) {
            vec.push_back({deadline[i], profit[i]});
        }
        
        sort(vec.begin(), vec.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) {
            
            if(vec[i].first > pq.size())
                pq.push(vec[i].second);
            
            else if(!pq.empty() && pq.top() < vec[i].second) {
                pq.pop();
                pq.push(vec[i].second);
            }
        }
        
        int cnt = pq.size();
        int sum = 0;
        while(pq.size()) {
            sum += pq.top();
            pq.pop();
        }
        
        return {cnt, sum};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends