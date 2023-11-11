const [startPlayer, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const board = [
  [0, 0, 0],
  [0, 0, 0],
  [0, 0, 0],
];

const checkWinner = () => {
  for (let r = 0; r < 3; r++) {
    if (board[r][0] === board[r][1] && board[r][1] === board[r][2] && board[r][0] !== 0) {
      return board[r][0];
    }
  }

  for (let c = 0; c < 3; c++) {
    if (board[0][c] === board[1][c] && board[1][c] === board[2][c] && board[0][c] !== 0) {
      return board[0][c];
    }
  }

  if (board[0][0] === board[1][1] && board[1][1] === board[2][2] && board[0][0] !== 0) {
    return board[0][0];
  }

  if (board[0][2] === board[1][1] && board[1][1] === board[2][0] && board[0][2] !== 0) {
    return board[0][2];
  }

  return 0;
}

let currentPlayer = Number(startPlayer);

for (let i = 0; i < 9; i++) {
  const [row, col] = input[i].split(' ').map((value) => Number(value) - 1);

  board[row][col] = currentPlayer;
  currentPlayer = 3 - currentPlayer;

  const winner = checkWinner();

  if (winner !== 0) {
    console.log(winner);
    return;
  }
}

console.log(0);
