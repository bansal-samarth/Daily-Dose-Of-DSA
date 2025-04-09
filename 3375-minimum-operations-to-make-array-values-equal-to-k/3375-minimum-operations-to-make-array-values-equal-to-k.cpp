class Solution {
public:
    int minOperations(vector<int>& x, int y) {
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());

        if (y > x.back()) return -1;
        if (x.front() < y) return -1;
        if (x.size() == 1 && x[0] == y) return 0;

        if (x[0] == y) {
            int z = 0;
            for (int w : x) {
                if (w > y) z++;
            }
            return z;
        }

        return x.size();
    }
};
