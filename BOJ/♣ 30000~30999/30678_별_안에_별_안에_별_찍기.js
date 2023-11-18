const N = Number(require('fs').readFileSync(0));
const grid = Array.from({ length: 5 ** N })
  .map(() => Array.from({ length: 5 ** N })
    .map(() => ' '));

const NEXT_POSITIONS = [
  [0, 2],
  [1, 2],
  [2, 0],
  [2, 1],
  [2, 2],
  [2, 3],
  [2, 4],
  [3, 1],
  [3, 2],
  [3, 3],
  [4, 1],
  [4, 3],
];

const drawStar = (level, startR, startC) => {
  if (level === 0) {
    grid[startR][startC] = '*';
    return;
  }

  const nextWidth = 5 ** (level - 1);

  for (let i = 0; i < 12; i++) {
    const r = NEXT_POSITIONS[i][0];
    const c = NEXT_POSITIONS[i][1];

    drawStar(level - 1, startR + nextWidth * r, startC + nextWidth * c);
  }
}

drawStar(N, 0, 0);

let output = '';

for (let r = 0; r < 5 ** N; r++) {
  for (let c = 0; c < 5 ** N; c++) {
    output += grid[r][c];
  }

  output += '\n';
}

console.log(output);
