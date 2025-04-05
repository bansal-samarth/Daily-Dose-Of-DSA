//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n, m;

    // 8 possible directions mein move karne ke liye arrays
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // DFS function jo connected land cells ko visit karega
    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[x][y] = true;  // current cell ko visited mark kar diya

        // 8 directions mein check karo
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];  // next x-coordinate
            int ny = y + dy[dir];  // next y-coordinate

            // Agar next cell grid ke andar hai, land hai, aur visited nahi hai
            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                grid[nx][ny] == 'L' && !visited[nx][ny]) {
                dfs(nx, ny, grid, visited);  // us cell ke liye bhi DFS call karo
            }
        }
    }

    // Main function jo islands count karega
    int countIslands(vector<vector<char>>& grid) {
        n = grid.size();       // total rows
        m = grid[0].size();    // total columns

        // visited matrix initialize kar diya
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;  // islands ka count

        // Har cell ko check karo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Agar land hai aur abhi tak visited nahi hai
                if (grid[i][j] == 'L' && !visited[i][j]) {
                    count++;  // naya island mila
                    dfs(i, j, grid, visited);  // us island ke sare parts visit karo
                }
            }
        }

        return count;  // total islands return karo
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends