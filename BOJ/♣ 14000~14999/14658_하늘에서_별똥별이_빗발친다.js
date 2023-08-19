const getCollectedStarCount = (row, col) => {
  let collectedStarCount = 0;

  stars.forEach(([r, c]) => {
    if (r >= row && r <= row + L && c >= col && c <= col + L) {
      collectedStarCount += 1;
    }
  })

  return collectedStarCount;
}

const [NMLK, ...arr] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const [L, K] = NMLK.split(' ').slice(2).map(Number);
const stars = arr.map((star) => star.split(' ').map(Number));
let bestCollectedStarCount = 0;

stars.forEach(([r, c]) => {
  const cStart = c - L;
  const cEnd = c;

  for (let i = cStart; i <= cEnd; i++) {
    bestCollectedStarCount = Math.max(
      bestCollectedStarCount,
      getCollectedStarCount(r, i)
    );
  }
});

console.log(K - bestCollectedStarCount);
