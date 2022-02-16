const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const len = parseInt(input[0]);

for (let i = 1; i <= len; i++) {
  input[i] = input[i].split(' ').map((x) => parseInt(x));
}

let dp = new Array(len + 1);
for (let i = 1; i <= len; i++) {
  dp[i] = [0, 0, 0];
}

dp[1] = input[1].slice();
for (let i = 2; i <= len; i++) {
  dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + input[i][0];
  dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + input[i][1];
  dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + input[i][2];
}

console.log(Math.min(dp[len][0], dp[len][1], dp[len][2]));