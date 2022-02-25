let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const maxRow = parseInt(input[0].split(' ')[0]);
const maxCol = parseInt(input[0].split(' ')[1]);
input.shift();
let year = 0;
let foundResult = false;

for (let i = 0; i < maxRow; i++) {
    input[i] = input[i].split(' ').map(Number);
}

while (foundResult === false) {
    let iceFoundCount = 0;
    meltIce();

    for (let i = 0; i < maxRow; i++) {
        for (let j = 0; j < maxCol; j++) {
            if (input[i][j] > 0) {
                iceFoundCount++;
                if (iceFoundCount === 2) foundResult = true;
                else {
                    checkIce(i, j);
                }
            }
        }
    }
    if (iceFoundCount === 0) {
        year = 0;
        foundResult = true;
    }
    restoreIce();
}

console.log(year);

// meltIce() - 빙하 녹이기 함수
function meltIce() {
    year++;
    for (let row = 0; row < maxRow; row++) {
        for (let col = 0; col < maxCol; col++) {
            if (input[row][col] !== 0) {

                if (row > 0) {
                    if (input[row - 1][col] === 0) input[row][col]--;
                }
                if (col > 0) {
                    if (input[row][col - 1] === 0) input[row][col]--;
                }
                if (row < maxRow - 1) {
                    if (input[row + 1][col] === 0) input[row][col]--;
                }
                if (col < maxCol - 1) {
                    if (input[row][col + 1] === 0) input[row][col]--;
                }

                if (input[row][col] <= 0) input[row][col] = -1;
            }
        }
    }

    // 빙수가 0이 되었던 수치를 임시로 -1로 설정해 준 후, 연산이 끝나면 0으로 변경
    for (let row = 0; row < maxRow; row++) {
        for (let col = 0; col < maxCol; col++) {
            if (input[row][col] === -1) input[row][col] = 0;
        }
    }
}

function checkIce(startRow, startCol) {
    let queue = [[startRow, startCol]];

    while (queue.length !== 0) {
        let temp = queue.shift();
        let row = temp[0];
        let col = temp[1];
        if (input[row][col] < 0) continue;
        input[row][col] *= -1;

        if (row > 0) {
            if (input[row - 1][col] > 0) queue.push([row - 1, col]);
        }
        if (col > 0) {
            if (input[row][col - 1] > 0) queue.push([row, col - 1]);
        }
        if (row < maxRow - 1) {
            if (input[row + 1][col] > 0) queue.push([row + 1, col]);
        }
        if (col < maxCol - 1) {
            if (input[row][col + 1] > 0) queue.push([row, col + 1]);
        }
    }
}

function restoreIce() {
    for (let i = 0; i < maxRow; i++) {
        for (let j = 0; j < maxCol; j++) {
            if (input[i][j] < 0) input[i][j] *= -1;
        }
    }
}
