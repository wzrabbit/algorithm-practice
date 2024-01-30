const simulateRow = (row) => {
  let frontCount = initFrontCount;

  for (let c = 0; c < C; c++) {
    frontCount += grid[row][c] === '#' ? -1 : 1;
  }

  let bestRowDiff = -Infinity;

  for (let c = 0; c < C; c++) {
    bestRowDiff = Math.max(
      bestRowDiff,
      columnFrontCount[c] * 2 - R + (grid[row][c] === '#' ? -2 : 2),
    );
  }

  return frontCount - bestRowDiff;
};

const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const [R, C] = input[0].split(' ').map(Number);
const grid = input.slice(1);
const columnFrontCount = new Array(C).fill(0);
let initFrontCount = 0;

for (let r = 0; r < R; r++) {
  for (let c = 0; c < C; c++) {
    if (grid[r][c] === '#') {
      initFrontCount += 1;
      columnFrontCount[c] += 1;
    }
  }
}

let bestFrontCount = 0;

for (let r = 0; r < R; r++) {
  const currentFrontCount = simulateRow(r);
  bestFrontCount = Math.max(bestFrontCount, currentFrontCount);
}

const bestBackCount = R * C - bestFrontCount;
console.log(bestFrontCount, bestBackCount);
