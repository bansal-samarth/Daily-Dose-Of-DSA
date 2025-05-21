class Solution {
public:
    int kthSmallest(int m, int n, int k) {
        int low = 1, high = n * m; // Search space: 1 to m*n
        int ans = n * m; // Initialize answer with the largest possible value

        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid overflow
            int cnt = 0; // Count numbers <= mid

            // For each row, count how many numbers are <= mid
            for (int i = 1; i <= m; ++i) {
                // Numbers in row i: i, 2i, 3i, ..., ni
                // The count is min(mid/i, n)
                cnt += min(mid / i, n);
            }

            // If count >= k, the answer is in the left half
            if (cnt >= k) {
                ans = mid;
                high = mid - 1;
            } 
            // Else, search the right half
            else {
                low = mid + 1;
            }
        }

        return ans; // The kth smallest number
    }
};