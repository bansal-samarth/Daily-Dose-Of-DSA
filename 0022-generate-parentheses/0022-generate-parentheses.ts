function solve(n: number, open: number, close: number, output: string, ans: string[]): void {
    if(open === n && close === n) {
        ans.push(output);
        return;
    }

    if(open < n) {
        output = output.concat("(");
        solve(n, open + 1, close, output, ans);
        output = output.slice(0, -1);
    }

    if(close < open) {
        output = output.concat(")");
        solve(n, open, close + 1, output, ans);
        output = output.slice(0, -1);
    }
}

function generateParenthesis(n: number): string[] {
    let ans : string[] = [];
    solve(n, 0, 0, "", ans);
    return ans;
};