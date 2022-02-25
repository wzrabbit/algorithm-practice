let input = parseInt(require('fs').readFileSync('/dev/stdin'));
let last = Math.abs(input);
let dp = [0, 1];

for (let i = 2; i <= last; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
}

if (input > 0) console.log('1\n' + dp[last]);
else if (input < 0) {
    if (last % 2 === 0) console.log('-1\n' + dp[last]);
    else console.log('1\n' + dp[last]);
}
else console.log('0\n0');