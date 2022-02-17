const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [plum, move] = input[0].split(' ').map((x) => parseInt(x));
const board = input.slice(1).map((x) => parseInt(x));
let dp = new Array(move + 1).fill(0).map((x) => new Array(plum).fill(0));
dp[0][0] = board[0] === 1 ? 1 : 0;
dp[1][0] = board[0] === 2 ? 1 : 0;

for (let i = 1; i < plum; i++) {
  dp[0][i] = dp[0][i - 1] + (board[i] === 1 ? 1 : 0);
  for (let j = 1; j <= move; j++) {
    dp[j][i] = Math.max(dp[j - 1][i - 1], dp[j][i - 1]) + (j % 2 + 1 === board[i] ? 1 : 0);
  }
}

max = 0;
for (let i = 0; i <= move; i++) {
  if (dp[i][plum - 1] > max) max = dp[i][plum - 1];
}

console.log(max);