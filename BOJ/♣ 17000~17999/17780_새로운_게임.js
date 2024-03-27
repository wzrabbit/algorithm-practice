const getPositionById = (id) => {
  for (let r = 0; r < N; r++) {
    for (let c = 0; c < N; c++) {
      for (let f = 0; f < board[r][c].length; f++) {
        const currentId = board[r][c][f].id;

        if (currentId === id) {
          return { row: r, col: c, floor: f };
        }
      }
    }
  }
};

const getReversedDirection = (direction) => {
  switch (direction) {
    case DIRECTION.RIGHT:
      return DIRECTION.LEFT;
    case DIRECTION.LEFT:
      return DIRECTION.RIGHT;
    case DIRECTION.UP:
      return DIRECTION.DOWN;
    case DIRECTION.DOWN:
      return DIRECTION.UP;
  }
};

const move = (row, col, floor, direction, color) => {
  if (color === COLOR.BLUE) {
    direction = getReversedDirection(direction);
    board[row][col][floor].direction = direction;
  }

  const nextRow = row + DR[direction];
  const nextCol = col + DC[direction];

  if (color === COLOR.BLUE) {
    if (
      nextRow < 0 ||
      nextRow >= N ||
      nextCol < 0 ||
      nextCol >= N ||
      boardColors[nextRow][nextCol] === COLOR.BLUE
    ) {
      return;
    }

    color = boardColors[nextRow][nextCol];
  }

  const movingGroup =
    color === COLOR.RED
      ? board[row][col].slice().reverse()
      : board[row][col].slice();

  board[nextRow][nextCol] = board[nextRow][nextCol].concat(movingGroup);
  board[row][col] = [];

  if (board[nextRow][nextCol].length >= 4) {
    shouldEndGame = true;
  }
};

const performTurn = () => {
  for (let id = 1; id <= K; id++) {
    const { row, col, floor } = getPositionById(id);
    const { direction } = board[row][col][floor];

    if (floor !== 0) {
      continue;
    }

    const nextRow = row + DR[direction];
    const nextCol = col + DC[direction];

    if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= N) {
      move(row, col, floor, direction, COLOR.BLUE);
      continue;
    }

    move(row, col, floor, direction, boardColors[nextRow][nextCol]);
  }
};

const playNewGame = () => {
  for (let t = 1; t <= TURN_LIMIT; t++) {
    performTurn();

    if (shouldEndGame) {
      console.log(t);
      return;
    }
  }

  console.log(-1);
};

const COLOR = {
  WHITE: 0,
  RED: 1,
  BLUE: 2,
};

const DIRECTION = {
  RIGHT: 1,
  LEFT: 2,
  UP: 3,
  DOWN: 4,
};

const TURN_LIMIT = 1000;

const DR = [0, 0, 0, -1, 1];
const DC = [0, 1, -1, 0, 0];

const input = require("fs").readFileSync(0, "utf-8").trim().split("\n");

const [N, K] = input[0].split(" ").map(Number);
const boardColors = input
  .slice(1, N + 1)
  .map((row) => row.split(" ").map(Number));
const board = Array.from({ length: N }).map(() =>
  Array.from({ length: N }).map(() => []),
);
input.slice(N + 1).forEach((piece, index) => {
  const [row, col, direction] = piece.split(" ").map(Number);
  board[row - 1][col - 1].push({ id: index + 1, direction });
});
let shouldEndGame = false;

playNewGame();
