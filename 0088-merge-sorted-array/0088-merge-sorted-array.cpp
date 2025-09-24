class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = m + n - 1;
        m--;
        n--;

        while(size >= 0) {
            if(n == -1 || (m != -1 && (nums1[m] > nums2[n]))) {
                nums1[size--] = nums1[m--];
            } else {
                nums1[size--] = nums2[n--];
            }
        }

        return;
    }
};