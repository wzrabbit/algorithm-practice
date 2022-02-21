const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((x) => parseInt(x));
input.pop();

let max = 0;
for (let i = 0; i < input.length; i++) {
  if (input[i] > max) max = input[i];
}

let dp = new Array(max + 1).fill(0).map((x) => new Array(max + 1).fill(0));
dp[0] = [0, ...new Array(max).fill(1)];
for (let i = 1; i <= max; i++) {
  dp[i][i] = dp[i - 1][i];
  for (let j = i + 1; j <= max; j++) {
    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
  }
}

let result = '';
for (let i = 0; i < input.length; i++) {
  let val = input[i];
  result += dp[val][val] + '\n';
}
console.log(result);