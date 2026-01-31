function longestCommonPrefix(strs: string[]): string {
    strs.sort();

    let str1 = strs[0];
    let str2 = strs[strs.length - 1];

    let mini = Math.min(str1.length, str2.length);

    for(let i = mini; i >= 0; i--) {
        let substr1 = str1.substring(0, i);
        let substr2 = str2.substring(0, i);

        if(substr1 == substr2)
            return substr1;
    }

    return "";
};