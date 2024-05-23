const input = require("fs").readFileSync(0, "utf-8").trim().split("\n");
const N = Number(input[0]);
const grid = input.slice(1).map((line) => line.split(" ").map(Number));
let result = "TRUE";
const correctSum = (N * (N ** 2 + 1)) / 2;

const matrixValues = new Set();

for (let r = 0; r < N; r++) {
  for (let c = 0; c < N; c++) {
    matrixValues.add(grid[r][c]);
  }
}

if (matrixValues.size !== N ** 2) {
  result = "FALSE";
}

for (let r = 0; r < N; r++) {
  let sum = 0;

  for (let c = 0; c < N; c++) {
    sum += grid[r][c];
  }

  if (sum !== correctSum) {
    result = "FALSE";
    break;
  }
}

for (let c = 0; c < N; c++) {
  let sum = 0;

  for (let r = 0; r < N; r++) {
    sum += grid[r][c];
  }

  if (sum !== correctSum) {
    result = "FALSE";
    break;
  }
}

let sum = 0;

for (let i = 0; i < N; i++) {
  sum += grid[i][i];
}

if (sum !== correctSum) {
  result = "FALSE";
}

sum = 0;

for (let i = 0; i < N; i++) {
  sum += grid[i][N - i - 1];
}

if (sum !== correctSum) {
  result = "FALSE";
}

console.log(result);
