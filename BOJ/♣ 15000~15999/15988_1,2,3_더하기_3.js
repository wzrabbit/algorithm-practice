const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);
let dp = [null, 1, 2, 4];
let memory = 3;
let result = '';

for (let i = 1; i < input.length; i++) {
    let current = input[i];
    memory++;
    for (memory; memory <= input[i]; memory++) {
        dp[memory] = (dp[memory - 1] + dp[memory - 2] + dp[memory - 3]) % 1000000009;
    }
    memory--;

    result += dp[input[i]] + '\n';
}

console.log(result);