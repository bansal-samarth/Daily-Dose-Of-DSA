class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int to_left = 0, to_right = n;
        
        for (int x : left) to_left = max(to_left, x);
        
        for (int x : right) to_right = min(to_right, x);
        
        return max(n - to_right, to_left);
    }
};