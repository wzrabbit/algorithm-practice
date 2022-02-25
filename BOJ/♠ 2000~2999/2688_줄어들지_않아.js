const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);
let dp = [null, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1];
let result = '';

for (let i = 1; i < input.length; i++) {
    if (input[i] * 10 + 1 <= dp.length) {
        result += getResult(input[i]) + '\n';
    }
    else {
        while ((dp.length - 1) / 10 < input[i]) {
            let currentIndex = dp.length - 1;
            dp[currentIndex + 1] = 1;
            for (let j = 2; j <= 10; j++) {
                dp[currentIndex + j] = dp[currentIndex + j - 1] + dp[currentIndex + j - 10];
            }
        }
        result += getResult(input[i]) + '\n';
    }
}

result = result.slice(0, -1);
console.log(result);

function getResult(num) {
    let index = num * 10 - 9;
    let currentResult = 0;

    for (let i = 0; i < 10; i++) {
        currentResult += dp[index + i];
    }
    return currentResult;
}