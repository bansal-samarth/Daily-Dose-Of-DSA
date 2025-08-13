class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int maxL = height[left];
        int maxR = height[right];

        int water = 0;

        while(left < right) {
            if(maxL < maxR) {
                water += maxL - height[left++];
                maxL = max(maxL, height[left]);
            } else {
                water += maxR - height[right--];
                maxR = max(maxR, height[right]);
            }
        }

        return water;
    }
};