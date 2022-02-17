const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [t, u, v] = input[0].split(' ').map((x) => parseInt(x));
const row = ' ' + input[1];
const col = ' ' + input[2];
let dp = new Array(row.length).fill(0).map((x) => new Array(col.length).fill(0));

let temp = 0;
for (let i = 1; i < row.length; i++) {
  temp += u;
  dp[i][0] = temp;
}

temp = 0;
for (let i = 1; i < col.length; i++) {
  temp += u;
  dp[0][i] = temp;
}

for (let r = 1; r < row.length; r++) {
  for (let c = 1; c < col.length; c++) {
    dp[r][c] = Math.max(
      row[r] === col[c] ? dp[r - 1][c - 1] + t : dp[r - 1][c - 1] + v,
      dp[r][c - 1] + u,
      dp[r - 1][c] + u
    );
  }
}

console.log(dp[row.length - 1][col.length - 1]);