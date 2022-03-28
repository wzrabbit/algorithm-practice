const input = parseInt(require('fs').readFileSync('/dev/stdin'));
let dp = [[null, 0, 1], [null, 0, 1], [null, 1, 0]];

for (let i = 3; i <= input; i++) {
    dp[0].push((dp[1][i - 1] + dp[2][i - 1]) % 1000000007);
    dp[1].push((dp[0][i - 1] + dp[2][i - 1]) % 1000000007);
    dp[2].push((dp[0][i - 1] + dp[1][i - 1]) % 1000000007);
}

console.log(dp[0][input]);