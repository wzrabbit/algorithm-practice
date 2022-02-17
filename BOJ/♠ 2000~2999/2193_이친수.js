const input = parseInt(require('fs').readFileSync('/dev/stdin'));
let dp = [null, 1n, 1n];

for (let i = 3; i <= input; i++) {
  dp[i] = (dp[i - 1] + dp[i - 2]);
}

console.log(dp[input].toString());