const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const puyoGame = [
  [], [], [], [], [], []
];
let puyoPopped = false;
let ren = 0;

for (let i = 0; i < 6; i++) {
  for (let j = 11; j >= 0; j--) {
    puyoGame[i].push(input[j][i]);
  }
}

while (true) {
  // 1. 뿌요 매칭 단계, 뿌요가 하나도 매칭되지 않으면 반복 종료
  for (let row = 0; row < 6; row++) {
    for (let col = 0; col < 12; col++) {
      if (['R', 'B', 'G', 'Y', 'P'].includes(puyoGame[row][col])) searchPuyo(row, col, puyoGame[row][col]);
    }
  }
  if (puyoPopped === true) puyoPopped = false;
  else break;

  // 2. 개수가 부족해 매칭되지 않은 뿌요는 원래 데이터로 초기화 진행
  for (let row = 0; row < 6; row++) {
    for (let col = 0; col < 12; col++) {
      if (puyoGame[row][col].length === 2) puyoGame[row][col] = puyoGame[row][col][0];
    }
  }

  // 3. 뿌요 매칭 후 빈 자리 처리
  for (let row = 0; row < 6; row++) {
    for (let col = 11; col >= 0; col--) {
      if (puyoGame[row][col] === '.') {
        puyoGame[row].splice(col, 1);
        puyoGame[row].push('.');
      }
    }
  }
  ren++;
}

console.log(ren);

function searchPuyo(startRow, startCol, color) {
  const queue = [[startRow, startCol]];
  let puyoCount = 0;
  let id = `(${startRow},${startCol})`;
  puyoGame[startRow][startCol] = color + id;

  while (queue.length !== 0) {
    const [row, col] = queue.shift();
    puyoCount++;

    if (row >= 1) {
      if (puyoGame[row - 1][col] === color) {
        queue.push([row - 1, col]);
        puyoGame[row - 1][col] = color + id;
      }
    }
    if (col >= 1) {
      if (puyoGame[row][col - 1] === color) {
        queue.push([row, col - 1]);
        puyoGame[row][col - 1] = color + id;
      }
    }
    if (row <= 4) {
      if (puyoGame[row + 1][col] === color) {
        queue.push([row + 1, col]);
        puyoGame[row + 1][col] = color + id;
      }
    }
    if (col <= 10) {
      if (puyoGame[row][col + 1] === color) {
        queue.push([row, col + 1]);
        puyoGame[row][col + 1] = color + id;
      }
    }
  }

  if (puyoCount >= 4) {
    puyoPopped = true;
    for (let row = 0; row < 6; row++) {
      for (let col = 0; col < 12; col++) {
        if (puyoGame[row][col] === color + id) puyoGame[row][col] = '.';
      }
    }
  }
  else {
    for (let row = 0; row < 6; row++) {
      for (let col = 0; col < 12; col++) {
        if (puyoGame[row][col] === color + id) puyoGame[row][col] = color + '+';
      }
    }
  }
}