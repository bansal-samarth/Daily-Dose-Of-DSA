//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &end) {
        vector<pair<int,int>> act;
        for(int i = 0; i < start.size(); i++)
            act.push_back({end[i], start[i]});
        
        sort(act.begin(), act.end());
        
        int num = 1;
        int ed = act[0].first;
        for(int i = 1; i < act.size(); i++) {
            if(act[i].second > ed) {
                num++;
                ed = act[i].first;
            }
        }
        
        return num;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> end;
        ss.str(input);
        while (ss >> num)
            end.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, end) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends