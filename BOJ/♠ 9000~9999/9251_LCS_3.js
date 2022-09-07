const [A, B, C] = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
const dp = Array.from(
    Array(A.length), () =>
    Array.from(Array(B.length), () => new Array(C.length).fill(0)));

for (let a = 0; a < A.length; a++) {
    for (let b = 0; b < B.length; b++) {
        for (let c = 0; c < C.length; c++) {
            if (A[a] === B[b] && B[b] === C[c] && A[a] === C[c])
                dp[a][b][c] = a === 0 || b === 0 || c === 0 ? 1 : dp[a - 1][b - 1][c - 1] + 1;
            else {
                dp[a][b][c] = Math.max(
                    a === 0 ? 0 : dp[a - 1][b][c],
                    b === 0 ? 0 : dp[a][b - 1][c],
                    c === 0 ? 0 : dp[a][b][c - 1]
                );
            }
        }
    }
}

console.log(dp[A.length - 1][B.length - 1][C.length - 1]);