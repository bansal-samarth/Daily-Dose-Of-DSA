class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left = 0;
        int right = n - 1;

        int maxL = height[0];
        int maxR = height[n - 1];

        int water = 0;

        while(left < right) {
            if(maxL < maxR) {
                water += maxL - height[left++];
                maxL = max(maxL, height[left]);
            }
            else {
                water += maxR - height[right--];
                maxR = max(maxR, height[right]);
            }
        }

        return water;
    }
};