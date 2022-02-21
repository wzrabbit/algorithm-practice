const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')[1].split(' ').map((x) => parseInt(x));
const len = input.length;
let dp = new Array(len - 1).fill(0).map((x) => new Array(21).fill(0n));

dp[0][input[0]] = 1n;
for (let i = 1; i < len - 1; i++) {
  for (let j = 0; j <= 20; j++) {
    if (j + input[i] >= 0 && j + input[i] <= 20) {
      dp[i][j] += dp[i - 1][j + input[i]];
    }
    if (j - input[i] >= 0 && j - input[i] <= 20) {
      dp[i][j] += dp[i - 1][j - input[i]];
    }
  }
}

let answer = dp[len - 2][input[len - 1]];
console.log(answer.toString());