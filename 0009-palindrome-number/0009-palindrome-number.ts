function isPalindrome(x: number): boolean {
    if(x < 0)
        return false;

    let num = x;
    let rev = 0;

    while(num != 0) {
        let rem = num % 10; // 1   -> 2
        rev = rev*10 + rem; // 1   -> 1*10 + 2 = 12
        num /= 10;          // 12 -> 1 
        num = Math.floor(num);
        console.log(rem, rev, num);
    }

    return rev === x;
};