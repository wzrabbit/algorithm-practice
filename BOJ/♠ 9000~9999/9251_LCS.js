const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const row = input[0];
const col = input[1];
let dp = new Array(row.length).fill(0).map((x) => new Array(col.length).fill(0));

for (let r = 0; r < row.length; r++) {
  for (let c = 0; c < col.length; c++) {
    if (row[r] === col[c]) dp[r][c] = r === 0 || c === 0 ? 1 : dp[r - 1][c - 1] + 1;
    else {
      dp[r][c] = Math.max(
        r === 0 ? 0 : dp[r - 1][c],
        c === 0 ? 0 : dp[r][c - 1]
      );
    }
  }
}

console.log(dp[row.length - 1][col.length - 1]);