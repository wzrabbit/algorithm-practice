const [NK, input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const [N, K] = NK.split(' ').map(Number);
let board = input.split('');

const changeBoard = () => {
  const tempBoard = [board[N - 1], ...board, board[0]];
  let newBoard = [];

  for (let i = 1; i <= N; i++) {
    let colors = { R: 0, G: 0, B: 0 };

    for (let j = i - 1; j <= i + 1; j++) {
      colors[tempBoard[j]] += 1;
    }

    colors = [...Object.entries(colors)];

    if (colors.filter(([_, value]) => value === 2).length === 0) {
      newBoard.push('B');
      continue;
    }

    const X = colors.filter(([_, value]) => value === 2)[0][0];
    const Y = colors.filter(([_, value]) => value === 1)[0][0];

    if (
      (X === 'R' && Y === 'G') ||
      (X === 'G' && Y === 'B') ||
      (X === 'B' && Y === 'R')
    ) {
      newBoard.push('G');
      continue;
    }

    newBoard.push('R');
  }

  board = newBoard;
};

for (let i = 0; i < K; i++) {
  changeBoard();
}

const colors = { R: 0, G: 0, B: 0 };

for (let i = 0; i < N; i++) {
  colors[board[i]] += 1;
}

console.log(colors.R, colors.G, colors.B);
