const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((x) => parseInt(x));
input.shift();

let max = 0;
for (let i = 0; i < input.length; i++) {
  if (input[i] > max && input[i] % 2 === 0) max = input[i];
}
max /= 2;

let dp = new Array(max + 1).fill(0).map((x) => new Array(max + 1).fill(0));
dp[0] = [0, ...new Array(max).fill(1)];
for (let i = 1; i <= max; i++) {
  dp[i][i] = dp[i - 1][i];
  for (let j = i + 1; j <= max; j++) {
    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
  }
}

let result = '';
for (let i = 0; i < input.length; i++) {
  let val = input[i] / 2;
  if (val % 1 === 0) result += dp[val][val] % 1000000007 + '\n';
  else result += '0\n';
}
console.log(result);