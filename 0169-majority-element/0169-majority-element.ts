function majorityElement(nums: number[]): number {

    let ans = 0;
    let cnt = 0;

    for(let i = 0; i < nums.length; i++) {
        if(cnt == 0) {
            ans = nums[i];
            cnt++;
        } else if(ans == nums[i])
            cnt++;
        else
            cnt--;
    }

    return ans;
};