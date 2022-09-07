const input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
const [N, first] = input[0].split(' ').map((x) => parseInt(x));
const [gg, gb, bg, bb] = input[1].split(' ').map((x) => parseFloat(x));
let dp = Array.from(Array(N + 1), () => new Array(2).fill(0));

if (first === 0) dp[0][0] = 1;
else dp[0][1] = 1;

for (let i = 1; i <= N; i++) {
    for (let j = 0; j < 2; j++) {
        dp[i][0] = dp[i - 1][0] * gg + dp[i - 1][1] * bg;
        dp[i][1] = dp[i - 1][0] * gb + dp[i - 1][1] * bb;
    }
}

console.log(
    Math.round(dp[N][0] * 1000) + '\n' +
    Math.round(dp[N][1] * 1000));