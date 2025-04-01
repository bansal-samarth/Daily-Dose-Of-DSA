class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left = 0, right = n - 1;
        int maxL = height[left], maxR = height[right];

        int area = 0;
        while(left < right) {
            if(maxL > maxR) {
                area += maxR - height[right--];
                maxR = max(maxR, height[right]);
            } else {
                area += maxL - height[left++];
                maxL = max(maxL, height[left]);
            }
        }

        return area;
    }
};