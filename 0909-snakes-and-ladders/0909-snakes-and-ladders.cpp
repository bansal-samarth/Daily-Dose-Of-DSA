class Solution {
public:
    pair<int,int> getIdx(int i, int size) {
        int x = size - 1 - (i - 1) / size;
        int y = (i - 1) % size;

        if((i - 1) / size == 1) 
            y = size - 1 - y;

        return {x, y};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int size = board.size();
        int target = size * size;

        queue<int> q;
        vector<bool> vis(target, false);
        int steps = 1;

        if(board[size - 1][0] == -1)
            q.push(1);
        else
            q.push(board[size - 1][0]);

        vis[1] = true;
        while(!q.empty()) {
            int n = q.size();

            while(n--) {

                int idx = q.front();
                q.pop();

                for(int move = 1; move <= 6; move++) {
                    int next = idx + move;

                    if(next > target) break;

                    auto [x, y] = getIdx(next, size);

                    if(board[x][y] != -1)
                        next = board[x][y];

                    if(next == target) {
                        return steps;
                    }

                    if(!vis[next]) {
                        q.push(next);
                        continue;
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};