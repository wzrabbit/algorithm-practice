const input = parseInt(require('fs').readFileSync('/dev/stdin'));
let dp = [null, 'CY', 'SK', 'CY', 'SK', 'SK'];

for (let i = 6; i <= input; i++) {
    if (dp[i - 1] === 'CY' || dp[i - 3] === 'CY' || dp[i - 4] === 'CY') dp[i] = 'SK';
    else dp[i] = 'CY';
}

console.log(dp[input]);