const [row, col] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map(Number);

let board = new Array(row + 1);
board[0] = new Array(col + 1).fill(0);
board[1] = [0, ...new Array(col).fill(1)];

for (let i = 2; i <= row; i++) {
    board[i] = [0, 1, ...new Array(col - 1).fill(0)];
}

for (let r = 2; r <= row; r++) {
    for (let c = 2; c <= col; c++) {
        board[r][c] = (board[r][c] + board[r - 1][c] + board[r][c - 1] + board[r - 1][c - 1]) % 1000000007;
    }
}

console.log(board[row][col]);