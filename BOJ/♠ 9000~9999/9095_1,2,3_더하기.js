let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);
input.shift();

let dp = [null, 1, 2, 4];
let result = '';

for (let i = 4; i <= 10; i++) {
  dp[i] = dp[i - 1] + dp[i -2] + dp[i - 3];
}

for (let i = 0; i < input.length; i++) {
  result += dp[input[i]] + '\n';
}
console.log(result);