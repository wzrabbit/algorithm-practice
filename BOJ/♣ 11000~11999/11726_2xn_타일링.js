const input = parseInt(require('fs').readFileSync('/dev/stdin'));
let dp = [null, 1, 2];

for (let i = 3; i <= input; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
}

console.log(dp[input]);