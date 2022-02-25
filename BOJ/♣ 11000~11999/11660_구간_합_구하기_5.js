const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [width, repeat] = input[0].split(' ').map(Number);
let result = '';

let board = Array(width + 1);
board[0] = Array(width + 1).fill(0);
for (let i = 1; i <= width; i++) {
  board[i] = [0, ...input[i].split(' ').map(Number)];
}

for (let r = 1; r <= width; r++) {
  for (let c = 1; c <= width; c++) {
    board[r][c] += board[r - 1][c];
  }
}

for (let r = 1; r <= width; r++) {
  for (let c = 1; c <= width; c++) {
    board[r][c] += board[r][c - 1];
  }
}

for (let i = width + 1; i < input.length; i++) {
  const [x1, y1, x2, y2] = input[i].split(' ').map(Number);
  result += board[x2][y2] - board[x2][y1 - 1] - board[x1 - 1][y2] + board[x1 - 1][y1 - 1] + '\n';
}

console.log(result);