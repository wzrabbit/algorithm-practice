const fs = require("fs");
const input = parseInt(fs.readFileSync("/dev/stdin"));

let board = [];
board[0] = 0;
board[1] = 1;

for (let i = 2; i <= input; i++) {
    board[i] = board[i - 2] + board[i - 1];
}

console.log(board[board.length - 1]);