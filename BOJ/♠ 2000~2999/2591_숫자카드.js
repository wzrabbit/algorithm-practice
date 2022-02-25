let input = require('fs').readFileSync('/dev/stdin').toString().trim();
input = input.replace(/10|20|30/g, 'X');
let dp = [1];

for (let i = 1; i < input.length; i++) {
    if (input[i] === 'X' || input[i - 1] === 'X') {
        dp[i] = dp[i - 1];
    }
    else if (input[i - 1] === '1' || input[i - 1] === '2' || (input[i - 1] === '3' && input[i] <= 4)) {
        dp[i] = (dp[i - 2] || 1) + dp[i - 1];
    }
    else {
        dp[i] = dp[i - 1];
    }
}

console.log(dp[dp.length - 1]);