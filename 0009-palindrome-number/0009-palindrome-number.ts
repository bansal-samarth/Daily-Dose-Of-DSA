function isPalindrome(x: number): boolean {
    if(x < 0)
        return false;

    let num = x;
    let rev = 0;

    while(num != 0) {
        let rem = num % 10;
        rev = rev*10 + rem;
        num = Math.floor(num/10);
    }

    return rev === x;
};