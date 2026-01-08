function romanToInt(s: string): number {
    let n : number = s.length;
    let i : number = 0;

    let map : {} = {
        M: 1000,
        D: 500,
        C: 100,
        L: 50,
        X: 10,
        V: 5,
        I: 1
    }

    let sum : number = 0;
    for(; i < n; i++) {
        if(i + 1 < n && map[s[i]] < map[s[i + 1]]) {
            sum += map[s[i + 1]] - map[s[i]];
            i++;
        } else {
            sum += map[s[i]];
        }
    }

    return sum;
};
