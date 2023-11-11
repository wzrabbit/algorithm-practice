const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const [N, M, R] = input[0].split(' ').map(Number);
const grid = input.slice(1).map((line) => line.split(' ').map(Number));

const spinFrame = (startR, startC, rowSize, colSize) => {
  const temp = grid[startR][startC];

  for (let c = startC; c < startC + colSize - 1; c++) {
    grid[startR][c] = grid[startR][c + 1];
  }

  for (let r = startR; r < startR + rowSize - 1; r++) {
    grid[r][startC + colSize - 1] = grid[r + 1][startC + colSize - 1];
  }

  for (let c = startC + colSize - 1; c > startC; c--) {
    grid[startR + rowSize - 1][c] = grid[startR + rowSize - 1][c - 1];
  }

  for (let r = startR + rowSize - 1; r > startR + 1; r--) {
    grid[r][startC] = grid[r - 1][startC];
  }

  grid[startR + 1][startC] = temp;
};

const spin = () => {
  const limit = Math.min(N, M) / 2;

  for (let i = 0; i < limit; i++) {
    spinFrame(i, i, N - i * 2, M - i * 2);
  }
};

for (let i = 0; i < R; i++) {
  spin();
}

let result = '';

for (let r = 0; r < N; r++) {
  result += `${grid[r].join(' ')}\n`;
}

console.log(result);
