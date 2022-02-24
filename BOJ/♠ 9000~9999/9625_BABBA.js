const fs = require("fs");
const input = parseInt(fs.readFileSync("/dev/stdin"));
let board = [[1, 0], [0, 1]];

for (let i = 2; i <= input; i++) {
    board[i] = [board[i - 1][0] + board[i - 2][0], board[i - 1][1] + board[i - 2][1]];
}

console.log(board[input][0] + " " + board[input][1]);