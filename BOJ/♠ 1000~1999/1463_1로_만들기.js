let input = parseInt(require('fs').readFileSync('/dev/stdin'));

let dp = [null, 0];

for (let i = 2; i <= input; i++) {
    let a, b, c;
    a = dp[i - 1] + 1; // 1을 빼는 방법
    b = (i % 2 === 0) ? dp[i / 2] + 1 : a + 1; // 2로 나누는 방법
    c = (i % 3 === 0) ? dp[i / 3] + 1 : a + 1; // 3으로 나누는 방법
    dp[i] = Math.min(a, b, c);
}

console.log(dp[input]);