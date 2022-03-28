const n = parseInt(require('fs').readFileSync('/dev/stdin'));
let dp = [1n];

for (let i = 0; i <= n - 1; i++) {
    let current = 0n;
    for (let j = 0; j <= i; j++) {
        current += dp[j] * dp[i - j];
    }
    dp.push(current);
}

console.log(dp.pop().toString());