class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        if(target < mat[0][0] || mat[n-1][m-1] < target)
            return false;
        
        int low = 0;
        int high = n-1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2; // Move mid slightly up
            if (mat[mid][0] <= target)
                low = mid;
            else
                high = mid - 1;
        }

        int row = low;
        cout << row ;
        low = 0;
        high = m-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(mat[row][mid] == target)
                return true;

            if(mat[row][mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return false;
    }
};