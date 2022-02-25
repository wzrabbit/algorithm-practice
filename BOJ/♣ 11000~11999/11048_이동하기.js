const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [row, col] = input[0].split(' ').map(Number);

let dp = [Array(col + 1).fill(0)]
for (let i = 1; i <= row; i++) {
    dp.push([0, ...input[i].split(' ').map(Number)]);
}

for (let r = 1; r <= row; r++) {
    for (let c = 1; c <= col; c++) {
        dp[r][c] = dp[r][c] + Math.max(dp[r - 1][c - 1], dp[r - 1][c], dp[r][c - 1]);
    }
}

console.log(dp[row][col]);