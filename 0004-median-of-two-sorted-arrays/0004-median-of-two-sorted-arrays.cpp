class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m > n)
            return findMedianSortedArrays(nums2, nums1);
        
        int start = 0;
        int end = m;

        while(start <= end) {
            int Px = start + (end - start)/2;
            int Py = (m + n + 1)/2 - Px;

            int a1 = (Px == 0) ? INT_MIN : nums1[Px-1];
            int b1 = (Py == 0) ? INT_MIN : nums2[Py-1];

            int a2 = (Px == m) ? INT_MAX : nums1[Px];
            int b2 = (Py == n) ? INT_MAX : nums2[Py];

            if(a1 <= b2 && b1 <= a2) {

                if((m + n) % 2)
                    return (double)max(a1, b1);
                
                return (max(a1, b1) + min(a2, b2))/2.0;
            }

            if(a1 > b2)
                end = Px - 1;
            else
                start = Px + 1;
        }

        return -1;
    }
};