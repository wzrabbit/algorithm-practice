const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const row = input[0];
const col = input[1];
let dp = new Array(row.length).fill(0).map((x) => new Array(col.length).fill(0));

for (let r = 0; r < row.length; r++) {
    for (let c = 0; c < col.length; c++) {
        if (row[r] === col[c]) dp[r][c] = r === 0 || c === 0 ? 1 : dp[r - 1][c - 1] + 1;
        else {
            dp[r][c] = Math.max(
                r === 0 ? 0 : dp[r - 1][c],
                c === 0 ? 0 : dp[r][c - 1]
            );
        }
    }
}
let answer = dp[row.length - 1][col.length - 1];
console.log(answer);

if (answer !== 0) {
    let [r, c] = [row.length - 1, col.length - 1];
    let word = [];
    while (r >= 0 && c >= 0 && dp[r][c] > 0) {
        if (r > 0 && dp[r - 1][c] === dp[r][c]) {
            r -= 1;
            continue;
        }
        if (c > 0 && dp[r][c - 1] === dp[r][c]) {
            c -= 1;
            continue;
        }
        word.push(row[r]);
        r -= 1;
        c -= 1;
    }
    console.log(word.reverse().join(''));
}