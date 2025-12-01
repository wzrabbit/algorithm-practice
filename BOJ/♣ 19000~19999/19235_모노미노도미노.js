class Board {
  static ROW = 6;
  static COLUMN = 4;
  static DR = [-1, 1, 0, 0];
  static DC = [0, 0, -1, 1];
  #board = Array.from({ length: Board.ROW }).map(() => Array.from({ length: Board.COLUMN }).map(() => 0));
  #id = 1;
  #score = 0;

  dropBlock(positions) {
    if (positions.length === 1) {
      const { c } = positions[0];
      this.#board[1][c] = this.#id;
    } else if (positions[0].r === positions[1].r) {
      this.#board[1][positions[0].c] = this.#id;
      this.#board[1][positions[1].c] = this.#id;
    } else {
      this.#board[0][positions[0].c] = this.#id;
      this.#board[1][positions[1].c] = this.#id;
    }

    this.#id += 1;

    while (true) {
      this.#performGravity();
      const shouldRemoveAgain = this.#removeBlocks();

      if (!shouldRemoveAgain) break;
    }
  }

  getScore() {
    return this.#score;
  }

  getTileCount() {
    let tileCount = 0;
  
    for (let r = 2; r < Board.ROW; r++) {
      for (let c = 0; c < Board.COLUMN; c++) {
        if (this.#board[r][c] !== 0) tileCount += 1;
      }
    }

    return tileCount;
  }

  #removeBlocks() {
    let hasFullLine = false;

    for (let r = 2; r < Board.ROW; r++) {
      let isCurrentLineFull = true;
  
      for (let c = 0; c < Board.COLUMN; c++) {
        if (this.#board[r][c] === 0) {
          isCurrentLineFull = false;
          break;
        }
      }

      if (isCurrentLineFull) {
        hasFullLine = true;
        this.#score += 1;

        for (let c = 0; c < Board.COLUMN; c++) {
          this.#board[r][c] = 0;
        }
      }
    }

    if (hasFullLine) return true;

    let overflowRowCount = 0;

    for (let r = 0; r < 2; r++) {
      for (let c = 0; c < Board.COLUMN; c++) {
        if (this.#board[r][c] !== 0) {
          overflowRowCount += 1;
          break;
        }
      }
    }

    for (let r = Board.ROW - 1; r >= Board.ROW - overflowRowCount; r--) {
      for (let c = 0; c < Board.COLUMN; c++) {
        this.#board[r][c] = 0;
      }
    }

    return overflowRowCount > 0;
  }

  #performGravity() {
    for (let r = Board.ROW - 1; r >= 0; r--) {
      for (let c = 0; c < Board.COLUMN; c++) {
        if (this.#board[r][c] === 0) continue;

        const parts = [{ r, c }];

        for (let i = 0; i < 4; i++) {
          const nr = r + Board.DR[i];
          const nc = c + Board.DC[i];

          if (nr >= 0 && nr < Board.ROW && nc >= 0 && nc < Board.COLUMN && this.#board[r][c] === this.#board[nr][nc]) {
            parts.push({ r: nr, c: nc });
            break;
          }
        }

        while (true) {
          let shouldPerformGravity = true;

          for (const part of parts) {
            if (
              part.r === 5 ||
              (this.#board[part.r + 1][part.c] !== 0 && this.#board[part.r + 1][part.c] !== this.#board[part.r][part.c])
            ) {
              shouldPerformGravity = false;
              break;
            }
          }

          if (!shouldPerformGravity) break;

          for (let i = 0; i < parts.length; i++) {
            const { r, c } = parts[i];
            this.#board[r + 1][c] = this.#board[r][c];
            this.#board[r][c] = 0;
            parts[i].r += 1;
          }
        }
      }
    }
  }
}

const convertQueryToPositions = (query) => {
  const [blockType, row, column] = query;

  if (blockType === 1) {
    return {
      normal: [{ r: row, c: column }],
      rotated: [{ r: column, c: 3 - row }],
    }
  }

  if (blockType === 2) {
    return {
      normal: [{ r: row, c: column }, { r: row, c: column + 1 }],
      rotated: [{ r: column, c: 3 - row }, { r: column + 1, c: 3 - row }],
    }
  }

  return {
    normal: [{ r: row, c: column }, { r: row + 1, c: column }],
    rotated: [{ r: column, c: 3 - row }, { r: column, c: 2 - row }],
  }
}

const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const queries = input.slice(1).map((query) => query.split(' ').map(Number));
const positions = queries.map((query) => convertQueryToPositions(query));
const normalBoard = new Board();
const rotatedBoard = new Board();

positions.forEach(({ normal, rotated }) => {
  normalBoard.dropBlock(normal);
  rotatedBoard.dropBlock(rotated);
});

console.log(normalBoard.getScore() + rotatedBoard.getScore());
console.log(normalBoard.getTileCount() + rotatedBoard.getTileCount());
