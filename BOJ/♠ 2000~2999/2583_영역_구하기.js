const stairs = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);
let dp = [null];

dp[1] = stairs[1];
dp[2] = stairs[1] + stairs[2];
dp[3] = Math.max(stairs[1], stairs[2]) + stairs[3];

for (let i = 4; i <= stairs[0]; i++) {
    let a, b;
    a = dp[i - 2] + stairs[i];
    b = dp[i - 3] + stairs[i - 1] + stairs[i];
    dp[i] = a > b ? a : b;
}

console.log(dp[stairs[0]]);