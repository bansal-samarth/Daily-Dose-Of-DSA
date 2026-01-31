function jump(nums: number[]): number {
    
    let jumps = 0;
    let currEnd = 0;
    let maxReach = 0;

    for(let i = 0; i < nums.length-1; i++) {
        maxReach = Math.max(maxReach, nums[i] + i);

        if(currEnd === i) {
            currEnd = maxReach;
            jumps++;
        }
    }

    return jumps;
};