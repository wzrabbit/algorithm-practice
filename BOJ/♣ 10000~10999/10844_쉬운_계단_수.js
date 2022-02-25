const num = parseInt(require('fs').readFileSync('/dev/stdin'));
let dp = new Array(num + 1).fill(0).map((x) => new Array(10).fill(0));
dp[1] = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1];

for (let i = 2; i <= num; i++) {
    dp[i][0] = dp[i - 1][1] % 1000000000;
    dp[i][9] = dp[i - 1][8] % 1000000000;
    for (let j = 1; j <= 8; j++) {
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
    }
}

const result = dp[num].reduce((a, b) => a + b, 0);
console.log(result % 1000000000);