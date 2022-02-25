const num = parseInt(require('fs').readFileSync('/dev/stdin'));
let dp = new Array(1024).fill(0).map((x) => new Array(num + 1).fill(0).map((x) => new Array(10).fill(0)));
let mod = 1000000000;
// dp[등장한 수(비트마스킹)][자릿수][현재 수]
for (let i = 1; i <= 9; i++) {
    dp[2 ** i][1][i] = 1;
}

for (let i = 1; i < num; i++) {
    for (let j = 0; j <= 1023; j++) {
        dp[j | 2 ** 0][i + 1][0] += dp[j][i][1] % mod;
        dp[j | 2 ** 9][i + 1][9] += dp[j][i][8] % mod;
        for (let h = 1; h <= 8; h++) {
            dp[j | 2 ** h][i + 1][h] += (dp[j][i][h - 1] + dp[j][i][h + 1]) % mod;
        }
    }
}

const result = dp[1023][num].reduce((a, b) => a + b, 0);
console.log(result % mod);