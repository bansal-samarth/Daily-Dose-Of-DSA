function twoSum(nums: number[], target: number): number[] {
    let map = new Map<number, number>();

    let len = nums.length;
    for(let i = 0; i < len; i++) {
        let find = target - nums[i];

        if(map.has(find)) {
            return [map.get(find)!, i];
        }

        map.set(nums[i], i);   
    }

    return [];
};