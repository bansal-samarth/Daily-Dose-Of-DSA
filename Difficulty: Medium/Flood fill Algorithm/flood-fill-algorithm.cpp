//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> vis, int newc, int oldc) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;
        
        if(grid[i][j] != oldc || vis[i][j])
            return;
        
        vis[i][j] = true;
        grid[i][j] = newc;
        
        dfs(grid, i+1, j, vis, newc, oldc);
        dfs(grid, i, j+1, vis, newc, oldc);
        dfs(grid, i, j-1, vis, newc, oldc);
        dfs(grid, i-1, j, vis, newc, oldc);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> grid = image;
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        if(newColor == grid[sr][sc]) return grid;
        
        dfs(grid, sr, sc, vis, newColor, grid[sr][sc]);
        
        return grid;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends