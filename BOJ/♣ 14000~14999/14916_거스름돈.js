const money = parseInt(require('fs').readFileSync('/dev/stdin'));
let dp = [null, -1, 1, -1, 2, 1, 3, 2, 4, 3];

for (let i = 10; i <= money; i++) {
    dp.push(dp[i - 2] > dp[i - 5] ? dp[i - 5] + 1 : dp[i - 2] + 1);
}

console.log(dp[money]);