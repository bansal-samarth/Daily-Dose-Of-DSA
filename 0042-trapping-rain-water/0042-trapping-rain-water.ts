function trap(height: number[]): number {
    
    let left     = 0;
    let leftMax  = height[left];
    let right    = height.length - 1;
    let rightMax = height[right];

    let water = 0;

    while(left < right) {
        if(leftMax < rightMax) {
            leftMax = Math.max(leftMax, height[++left]);
            water += leftMax - height[left];
        } else {
            rightMax = Math.max(rightMax, height[--right]);
            water += rightMax - height[right];
        }
    }

    return water;
};