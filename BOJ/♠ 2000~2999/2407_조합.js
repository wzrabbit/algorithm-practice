const [n, m] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map((x) => BigInt(x));
let dp = [1n];
let dpLimit = (n > m) ? n : m;
for (let i = 1; i <= dpLimit; i++) {
    dp[i] = dp[i - 1] * BigInt(i);
}

console.log((dp[n] / dp[n - m] / dp[m]).toString());