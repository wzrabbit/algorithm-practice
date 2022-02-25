const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let result = '';
const numbers = input[1].split(' ').map(Number);
let dp = [numbers[0]];

for (let i = 1; i < numbers.length; i++) {
    dp[i] = dp[i - 1] + numbers[i];
}

for (let i = 2; i < input.length; i++) {
    let [start, end] = input[i].split(' ').map(Number);
    result += dp[end - 1] - (dp[start - 2] || 0) + '\n';
}

console.log(result);