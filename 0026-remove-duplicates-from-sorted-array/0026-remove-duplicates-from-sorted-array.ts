function removeDuplicates(nums: number[]): number {
    
    let size = nums.length;
    let curr = 0;
    for(let i = 1; i < size; i++) {
        if(nums[curr] == nums[i]) {
            continue;
        } else {
            curr++;
            nums[curr] = nums[i];
        }
    }

    return curr + 1;
};