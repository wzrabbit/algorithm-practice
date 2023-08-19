const catchFish = (fisherPosition) => {
  for (let r = 0; r < R; r++) {
    if (grid[r][fisherPosition].length === 1) {
      const { size } = grid[r][fisherPosition].pop();
      caughtSize += size;
      return;
    }
  }
}

const getNextPosition = (row, col, speed, direction) => {
  if (direction <= 2) {
    let remainDistance = speed % (R * 2 - 2);

    while (remainDistance > 0) {
      let currentDistance = Math.min(remainDistance, direction === 1 ? row : R - row - 1);
      row += direction === 1 ? -currentDistance : currentDistance;
      remainDistance -= currentDistance;

      if (row === 0 || row === R - 1) {
        direction = 3 - direction;
      }
    }
  } else {
    let remainDistance = speed % (C * 2 - 2);

    while (remainDistance > 0) {
      let currentDistance = Math.min(remainDistance, direction === 4 ? col : C - col - 1);
      col += direction === 4 ? -currentDistance : currentDistance;
      remainDistance -= currentDistance;

      if (col === 0 || col === C - 1) {
        direction = 7 - direction;
      }
    }
  }

  return { row, col, newDirection: direction };
}

const moveFishes = () => {
  const newGrid = Array.from({ length: R }).map(
    () => new Array(C).fill('').map(
      () => ([])
    )
  );

  for (let r = 0; r < R; r++) {
    for (let c = 0; c < C; c++) {
      grid[r][c].forEach(({ speed, direction, size }) => {
        const { row, col, newDirection } = getNextPosition(r, c, speed, direction);
        newGrid[row][col].push({ speed, direction: newDirection, size });
      });
    }
  }

  grid = newGrid;
}

const eatFishes = () => {
  for (let r = 0; r < R; r++) {
    for (let c = 0; c < C; c++) {
      if (grid[r][c].length > 0) {
        grid[r][c].sort((a, b) => b.size - a.size);
        grid[r][c] = [grid[r][c][0]];
      }
    }
  }
}

const [RCM, ...arr] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const [R, C] = RCM.split(' ').map(Number);
let caughtSize = 0;

let grid = Array.from({ length: R }).map(
  () => new Array(C).fill('').map(
    () => ([])
  )
);

arr.forEach((shark) => {
  const [row, col, speed, direction, size] = shark.split(' ').map(Number);
  grid[row - 1][col - 1].push({ speed, direction, size });
});

for (let p = 0; p < C; p++) {
  catchFish(p);
  moveFishes();
  eatFishes();
}

console.log(caughtSize);
