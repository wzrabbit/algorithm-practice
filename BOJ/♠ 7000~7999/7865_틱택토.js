const isWin = (board, player) => {
  for (let r = 0; r < 3; r++) {
    if (board[r].every((cell) => cell === player)) {
      return true;
    }
  }

  for (let c = 0; c < 3; c++) {
    if ([board[0][c], board[1][c], board[2][c]].every((cell) => cell === player)) {
      return true;
    }
  }

  if ([board[0][0], board[1][1], board[2][2]].every((cell) => cell === player)) {
    return true;
  }

  if ([board[0][2], board[1][1], board[2][0]].every((cell) => cell === player)) {
    return true;
  }

  return false;
}

const getCellCount = (board, player) => {
  let cellCount = 0;

  for (let r = 0; r < 3; r++) {
    for (let c = 0; c < 3; c++) {
      if (board[r][c] === player) {
        cellCount += 1;
      }
    }
  }

  return cellCount;
}

const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

input.pop();

let printer = '';

input.forEach((testcase) => {
  const board = testcase.match(/.{3}/g).map((row) => row.split(''));
  let isValid = true;

  const isOWin = isWin(board, 'O');
  const isXWin = isWin(board, 'X');
  const oCount = getCellCount(board, 'O');
  const xCount = getCellCount(board, 'X');
  const dotCount = getCellCount(board, '.');

  if (isOWin && isXWin) {
    isValid = false;
  }

  if (!isOWin && !isXWin && dotCount > 0) {
    isValid = false;
  }

  if (isOWin && oCount !== xCount) {
    isValid = false;
  }

  if (!isOWin && xCount - oCount !== 1) {
    isValid = false;
  }

  printer += isValid ? 'valid\n' : 'invalid\n';
});

console.log(printer);