const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let result = '';

for (let i = 1; i < input.length; i += 3) {
    const len = parseInt(input[i]);
    const board = [
        input[i + 1].split(' ').map((x) => parseInt(x)),
        input[i + 2].split(' ').map((x) => parseInt(x))
    ];
    let dp = new Array(2).fill(0).map((x) => new Array(len).fill(0));
    dp[0][0] = board[0][0];
    dp[1][0] = board[1][0];

    for (let j = 0; j < len - 2; j++) {
        dp[0][j + 1] = Math.max(dp[1][j] + board[0][j + 1], dp[0][j + 1]);
        dp[0][j + 2] = Math.max(dp[1][j] + board[0][j + 2], dp[0][j + 2]);
        dp[1][j + 1] = Math.max(dp[0][j] + board[1][j + 1], dp[1][j + 1]);
        dp[1][j + 2] = Math.max(dp[0][j] + board[1][j + 2], dp[1][j + 2]);
    }
    if (len >= 2) {
        dp[0][len - 1] = Math.max(dp[1][len - 2] + board[0][len - 1], dp[0][len - 1]);
        dp[1][len - 1] = Math.max(dp[0][len - 2] + board[1][len - 1], dp[1][len - 1]);
    }
    result += Math.max(dp[0][len - 1], dp[1][len - 1]) + '\n';
}

console.log(result);