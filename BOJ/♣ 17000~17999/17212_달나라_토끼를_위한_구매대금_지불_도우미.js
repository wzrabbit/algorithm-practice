let input = parseInt(require('fs').readFileSync('/dev/stdin'));
let dp = [0, 1, 1, 2, 2, 1, 2, 1];

for (let i = 8; i <= input; i++) {
    dp[i] = Math.min(dp[i - 1], dp[i - 2], dp[i - 5], dp[i - 7]) + 1;
}

console.log(dp[input]);