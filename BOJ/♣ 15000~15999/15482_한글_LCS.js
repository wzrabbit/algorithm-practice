const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const strA = ' ' + input[0];
const strB = ' ' + input[1];
let dp = Array.from(Array(strA.length), () => new Array(strB.length).fill(0));

for (let a = 1; a < strA.length; a++) {
    for (let b = 1; b < strB.length; b++) {
        dp[a][b] = Math.max(
            dp[a - 1][b],
            dp[a][b - 1],
            dp[a - 1][b - 1] + ((strA[a] === strB[b]) ? 1 : 0)
        );
    }
}

console.log(dp[strA.length - 1][strB.length - 1]);