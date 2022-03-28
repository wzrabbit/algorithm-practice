let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const maxRow = parseInt(input[0].split(' ')[0]);
const maxCol = parseInt(input[0].split(' ')[1]);
let max = 0;
input.shift();

for (let i = 0; i < maxRow; i++) {
    input[i] = input[i].split(' ').map(Number);
}

// I 블록
calcTetro([0, 0], [1, 0], [2, 0], [3, 0], 4, 1);
calcTetro([0, 0], [0, 1], [0, 2], [0, 3], 1, 4);

// 네모 블록
calcTetro([0, 0], [1, 0], [0, 1], [1, 1], 2, 2);

// L 블록
calcTetro([0, 0], [1, 0], [2, 0], [2, 1], 3, 2);
calcTetro([0, 0], [1, 0], [0, 1], [0, 2], 2, 3);
calcTetro([0, 0], [0, 1], [1, 1], [2, 1], 3, 2);
calcTetro([1, 0], [1, 1], [1, 2], [0, 2], 2, 3);
calcTetro([2, 0], [2, 1], [1, 1], [0, 1], 3, 2);
calcTetro([0, 0], [0, 1], [0, 2], [1, 2], 2, 3);
calcTetro([0, 0], [1, 0], [2, 0], [0, 1], 3, 2);
calcTetro([0, 0], [1, 0], [1, 1], [1, 2], 2, 3);

// Z 블록
calcTetro([0, 0], [1, 0], [1, 1], [2, 1], 3, 2);
calcTetro([1, 0], [1, 1], [0, 1], [0, 2], 2, 3);
calcTetro([1, 0], [2, 0], [0, 1], [1, 1], 3, 2);
calcTetro([0, 0], [0, 1], [1, 1], [1, 2], 2, 3);

// T 블록
calcTetro([0, 0], [1, 0], [1, 1], [2, 0], 3, 2);
calcTetro([0, 0], [0, 1], [0, 2], [1, 1], 2, 3);
calcTetro([1, 0], [1, 1], [0, 1], [2, 1], 3, 2);
calcTetro([1, 0], [1, 1], [1, 2], [0, 1], 2, 3);

console.log(max);

function calcTetro([r1, c1], [r2, c2], [r3, c3], [r4, c4], row, col) {
    for (let i = 0; i < maxRow - row + 1; i++) {
        for (let j = 0; j < maxCol - col + 1; j++) {
            let current = 0;
            current += input[r1 + i][c1 + j];
            current += input[r2 + i][c2 + j];
            current += input[r3 + i][c3 + j];
            current += input[r4 + i][c4 + j];
            if (current > max) max = current;
        }
    }
}
