const resetMark = () => {
  mark = Array(7)
    .fill("")
    .map(() => Array(7).fill(false));
};

const paintMark = (player) => {
  for (let r = 1; r <= 6; r++) {
    for (let c = 1; c <= 6; c++) {
      if (mark[r][c] === true) {
        board[r][c] = player;
      }
    }
  }
};

const traverse = (row, col, player, directionIndex) => {
  let [currentRow, currentCol] = [
    row + dr[directionIndex],
    col + dc[directionIndex],
  ];
  mark[row][col] = true;

  while (
    currentRow >= 1 &&
    currentRow <= 6 &&
    currentCol >= 1 &&
    currentCol <= 6 &&
    board[currentRow][currentCol] !== "."
  ) {
    mark[currentRow][currentCol] = true;

    if (player === board[currentRow][currentCol]) {
      paintMark(player);
      return;
    }

    currentRow += dr[directionIndex];
    currentCol += dc[directionIndex];
  }
};

const performMove = (player, row, col) => {
  for (let index = 0; index < 8; index++) {
    resetMark();
    traverse(row, col, player, index);
  }
};

const getWinner = () => {
  let blackCount = 0;
  let whiteCount = 0;

  for (let r = 1; r <= 6; r++) {
    for (let c = 1; c <= 6; c++) {
      if (board[r][c] === "B") {
        blackCount += 1;
      } else if (board[r][c] === "W") {
        whiteCount += 1;
      }
    }
  }

  return blackCount > whiteCount ? "Black" : "White";
};

const printResult = () => {
  for (let r = 1; r <= 6; r++) {
    console.log(board[r].slice(1).join(""));
  }
  console.log(getWinner());
};

const [, ...input] = require("fs").readFileSync(0, "utf-8").trim().split("\n");
let mark;
const dr = [-1, -1, -1, 0, 0, 1, 1, 1];
const dc = [-1, 0, 1, -1, 1, -1, 0, 1];

let board = Array(7)
  .fill("")
  .map(() => Array(7).fill("."));

board[3][3] = board[4][4] = "W";
board[3][4] = board[4][3] = "B";

input.forEach((testcase, index) => {
  const [row, col] = testcase.split(" ").map(Number);
  const player = index % 2 === 0 ? "B" : "W";

  performMove(player, row, col);
});

printResult();
