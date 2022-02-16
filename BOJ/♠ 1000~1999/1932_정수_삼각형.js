let triangle = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const scale = parseInt(triangle[0]);
triangle.shift();
for (let i = 0; i < triangle.length; i++) {
  triangle[i] = triangle[i].split(' ').map(Number);
}

let dp = [triangle[0][0]];
let tempdp = [];

for (let i = 1; i < scale; i++) {
  // 첫째 항
  tempdp[0] = dp[0] + triangle[i][0];
  // 중간 항
  for (let j = 1; j < i; j++) {
    tempdp[j] = Math.max(dp[j - 1], dp[j]) + triangle[i][j];
  }
  // 마지막 항
  tempdp[i] = dp[i - 1] + triangle[i][i];

  dp = tempdp.slice();
  tempdp = [];
}

let max = 0;
for (let i = 0; i < scale; i++) {
  if (dp[i] > max) max = dp[i];
}
console.log(max);