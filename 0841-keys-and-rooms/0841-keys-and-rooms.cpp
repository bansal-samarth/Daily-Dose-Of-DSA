class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int room, vector<bool>& vis) {
        vis[room] = true;

        for(int key : rooms[room]) {
            if(!vis[key]) {
                dfs(rooms, key, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> vis(n, false);

        dfs(rooms, 0, vis);

        for(bool v : vis) {
            if(!v) return false;
        }

        return true;
    }
};