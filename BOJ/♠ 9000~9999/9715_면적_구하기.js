const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let index = 1;
let cases = parseInt(input[0]);
let result = '';

for (let i = 0; i < cases; i++) {
  let [row, col] = input[index].split(' ').map(Number);
  let board = [];
  let area = 0;
  index++;

  for (let j = 0; j < row; j++) {
    board.push(input[index].split('').map(Number));
    index++;
  }

  for (let r = 0; r < row; r++) {
    for (let c = 0; c < col; c++) {
      if (board[r][c] !== 0) {
        area += 2;
        if (r > 0) {
          if (board[r][c] - board[r - 1][c] > 0) area += board[r][c] - board[r - 1][c];
        }
        else area += board[r][c];
        if (r < row - 1) {
          if (board[r][c] - board[r + 1][c] > 0) area += board[r][c] - board[r + 1][c];
        }
        else area += board[r][c];
        if (c > 0) {
          if (board[r][c] - board[r][c - 1] > 0) area += board[r][c] - board[r][c - 1];
        }
        else area += board[r][c];
        if (c < col - 1) {
          if (board[r][c] - board[r][c + 1] > 0) area += board[r][c] - board[r][c + 1];
        }
        else area += board[r][c];
      }
    }
  }

  result += area + '\n';
}

console.log(result);