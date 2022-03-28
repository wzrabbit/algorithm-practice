const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const len = parseInt(input[0]);

for (let i = 1; i <= len; i++) {
    input[i] = input[i].split(' ').map((x) => parseInt(x));
}

function getDP(start, ban) {
    let dp = new Array(len + 1);
    for (let i = 1; i <= len; i++) {
        dp[i] = [0, 0, 0];
    }
    dp[1] = start;
    for (let i = 2; i <= len; i++) {
        dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + input[i][0];
        dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + input[i][1];
        dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + input[i][2];
    }
    if (ban === 'R') return (Math.min(dp[len][1], dp[len][2]));
    if (ban === 'G') return (Math.min(dp[len][0], dp[len][2]));
    if (ban === 'B') return (Math.min(dp[len][0], dp[len][1]));
}

console.log(Math.min(
    getDP([input[1][0], 99999999, 99999999], 'R'),
    getDP([99999999, input[1][1], 99999999], 'G'),
    getDP([99999999, 99999999, input[1][2]], 'B')
));