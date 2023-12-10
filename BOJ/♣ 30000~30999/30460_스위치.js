const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const N = Number(input[0]);
const scores = [0, ...input[1].split(' ').map(Number), 0, 0];
const dp = Array.from({ length: N + 3 }).map(() => 0);

for (let i = 1; i <= N + 2; i++) {
  dp[i] = dp[i - 1] + scores[i];

  if (i >= 3) {
    dp[i] = Math.max(dp[i], dp[i - 3] + 2 * (scores[i - 2] + scores[i - 1] + scores[i]));
  }
}

console.log(dp[N + 2]);
