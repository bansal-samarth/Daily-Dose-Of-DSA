/**
 * @param {string} s
 * @return {number}
 */

var map = {
    M: 1000,
    D: 500,
    C: 100,
    L: 50,
    X: 10,
    V: 5,
    I: 1
}

var romanToInt = function(s) {
    let n = s.length;
    let i = 0;

    let sum = 0;
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