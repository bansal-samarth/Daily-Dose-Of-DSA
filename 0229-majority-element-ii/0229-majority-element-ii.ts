function majorityElement(nums: number[]): number[] {
    
    let num1 = nums[0];
    let cnt1 = 0;
    let num2 = 0;
    let cnt2 = 0;

    for(let i = 0; i < nums.length; i++) {
        if(num1 == nums[i] || (cnt1 == 0 && num2 !== nums[i])) {
            num1 = nums[i];
            cnt1++;
        } else if(num2 == nums[i] || cnt2 == 0) {
            num2 = nums[i];
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    let res : number[] = [];
    let res1 = 0;
    let res2 = 0;

    for(let i = 0; i < nums.length; i++) {
        if(num1 == nums[i])
            res1++;
        else if(num2 == nums[i])
            res2++;
    }

    if(res1 > (nums.length/3))
        res.push(num1);
    if(res2 > (nums.length/3))
        res.push(num2);
    
    return res;
};