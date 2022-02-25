const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').pop().split(' ').map(Number);
let dp = [1];
let maxLength = 1;

for (let i = 1; i < input.length; i++) {
    let maxValue = 0;
    for (let j = 0; j <= i - 1; j++) {
        if (input[j] > input[i] && maxValue < dp[j] + 1) maxValue = dp[j] + 1;
    }
    dp[i] = maxValue;
    if (dp[i] === 0) dp[i] = 1;
    if (dp[i] > maxLength) maxLength = dp[i];
}

console.log(maxLength);