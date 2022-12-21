const fillGrid = () => {
  let pointer = 0;

  for (let r = 0; r < R; r++) {
    for (let c = 0; c < C; c++) {
      grid[r][c] = drrdr[pointer];
      pointer = (pointer + 1) % 5;
    }
  }
};

const getCellCount = (curR, curC, no) => {
  let curCount = 0;
  visited[curR][curC] = true;

  for (let i = 0; i < 4; i++) {
    const nextR = curR + dr[i];
    const nextC = curC + dc[i];

    if (
      nextR >= 0 &&
      nextR < R &&
      nextC >= 0 &&
      nextC < C &&
      !visited[nextR][nextC] &&
      grid[nextR][nextC] === drrdr[no + 1]
    ) {
      if (no === 3) curCount++;
      else curCount += getCellCount(nextR, nextC, no + 1);
    }
  }
  visited[curR][curC] = false;
  return curCount;
};

const getAreaCount = (startRow, startCol, endRow, endCol) => {
  let countResult = 0;
  for (let r = startRow; r < endRow; r++) {
    for (let c = startCol; c < endCol; c++) {
      if (grid[r][c] === "D") {
        countResult += getCellCount(r, c, 0);
      }
    }
  }
  return countResult;
};

const [inputR, inputC] = require("fs")
  .readFileSync(0, "utf-8")
  .trim()
  .split(" ")
  .map(Number);

let [R, C] = [inputR, inputC];
if (R >= 13) R = ((R - 13) % 5) + 13;
if (C >= 13) C = ((C - 13) % 5) + 13;

let grid = Array.from(Array(R), () => Array(C).fill(null));
let visited = Array.from(Array(R), () => Array(C).fill(false));
let dr = [-1, 1, 0, 0];
let dc = [0, 0, -1, 1];
const drrdr = ["D", "R", "R", "D", "R"];
let finalResult = 0;

fillGrid();

if (inputR < 13 && inputC < 13) {
  finalResult = getAreaCount(0, 0, inputR, inputC);
}

if (inputR >= 13 && inputC < 13) {
  const repeat = Math.floor((inputR - 8) / 5);
  const frag = (inputR - 8) % 5;
  finalResult =
    getAreaCount(0, 0, 4, C) +
    getAreaCount(4, 0, 9, C) * repeat +
    getAreaCount(4, 0, 4 + frag, C) +
    getAreaCount(R - 4, 0, R, C);
}

if (inputR < 13 && inputC >= 13) {
  const repeat = Math.floor((inputC - 8) / 5);
  const frag = (inputC - 8) % 5;
  finalResult =
    getAreaCount(0, 0, R, 4) +
    getAreaCount(0, 4, R, 9) * repeat +
    getAreaCount(0, 4, R, 4 + frag) +
    getAreaCount(0, C - 4, R, C);
}

if (inputR >= 13 && inputC >= 13) {
  const repeatR = Math.floor((inputR - 8) / 5);
  const fragR = (inputR - 8) % 5;
  const repeatC = Math.floor((inputC - 8) / 5);
  const fragC = (inputC - 8) % 5;

  // Top Edge
  finalResult +=
    getAreaCount(0, 0, 4, 4) +
    getAreaCount(0, 4, 4, 9) * repeatC +
    getAreaCount(0, 4, 4, 4 + fragC) +
    getAreaCount(0, C - 4, 4, C);

  // Bottom Edge
  finalResult +=
    getAreaCount(R - 4, 0, R, 4) +
    getAreaCount(R - 4, 4, R, 9) * repeatC +
    getAreaCount(R - 4, 4, R, 4 + fragC) +
    getAreaCount(R - 4, C - 4, R, C);

  // Left Edge
  finalResult +=
    getAreaCount(4, 0, 9, 4) * repeatR + getAreaCount(4, 0, 4 + fragR, 4);

  // Right Edge
  finalResult +=
    getAreaCount(4, C - 4, 9, C) * repeatR +
    getAreaCount(4, C - 4, 4 + fragR, C);

  // Mid Core
  finalResult += getAreaCount(4, 4, 9, 9) * repeatR * repeatC;

  // Right Core
  finalResult += getAreaCount(4, 4, 9, 4 + fragC) * repeatR;

  // Bottom Core
  finalResult += getAreaCount(4, 4, 4 + fragR, 9) * repeatC;

  // Bottom-Right Core
  finalResult += getAreaCount(4, 4, 4 + fragR, 4 + fragC);
}

console.log(finalResult);
