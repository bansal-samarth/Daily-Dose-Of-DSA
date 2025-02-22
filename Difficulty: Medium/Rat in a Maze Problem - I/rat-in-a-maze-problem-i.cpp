//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void solve(vector<vector<int>> &mat, int r, int c, vector<string> &ans, string str) {
        if(r < 0 || c < 0 || r >= mat.size() || c >= mat.size() || !mat[r][c])
            return;
        
        if(r == mat.size()-1 && c == mat.size()-1) {
            ans.push_back(str);
            return;
        }
        mat[r][c] = 0;
        
        solve(mat, r+1, c, ans, str + "D");
        solve(mat, r, c-1, ans, str + "L");
        solve(mat, r, c+1, ans, str + "R");
        solve(mat, r-1, c, ans, str + "U");
        
        mat[r][c] = 1;
        
        return;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        if(mat[0][0] == 0 || mat[n-1][n-1] == 0)
            return {};
        
        vector<string> ans;
        solve(mat, 0, 0, ans, "");
        return ans;
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
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends