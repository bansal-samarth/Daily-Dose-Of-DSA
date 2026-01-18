const pow = (x : number, y : number): number => {
    if(y === 0)
        return 1;
    if(y === 1)
        return x;
    
    if(y % 2 === 0) {
        let res = pow(x, y/2);
        return res * res;
    } else
        return x * pow(x, y - 1);
}

function myPow(x: number, n: number): number {
    
    let ans = pow(x, Math.abs(n));

    if(n < 0)
        return 1/ans;
    return ans;
};