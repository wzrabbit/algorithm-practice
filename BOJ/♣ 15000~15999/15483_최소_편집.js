const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const row = ' ' + input[0];
const col = ' ' + input[1];
let dp = new Array(row.length).fill(0).map((x) => new Array(col.length).fill(0));

dp[0][0] = 0;
for (let i = 1; i < row.length; i++) {
    dp[i][0] = i;
}
for (let i = 1; i < col.length; i++) {
    dp[0][i] = i;
}

for (let r = 1; r < row.length; r++) {
    for (let c = 1; c < col.length; c++) {
        let mul = 1;
        if (row[r] === col[c]) mul -= 1;
        dp[r][c] = Math.min(
            dp[r - 1][c - 1] + mul, // 교체
            dp[r][c - 1] + 1, // 삭제
            dp[r - 1][c] + 1 // 삽입
        );
    }
}

console.log(dp[row.length - 1][col.length - 1]);