let input = parseInt(require('fs').readFileSync('/dev/stdin'));
let dp = [0, 1];

for (let i = 2; i <= input; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
}

console.log(dp[input]);