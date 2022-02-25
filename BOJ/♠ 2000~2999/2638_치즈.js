const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [masterRow, masterCol] = input[0].split(' ').map(Number);
input.shift();
let time = 0;

for (let i = 0; i < masterRow; i++) {
    input[i] = input[i].split(' ');
}

while (isRemainCheese()) {
    time++;
    searchEmptySpace();
    meltCheese();
}

console.log(time);

// 1. 치즈가 남아있는지 확인
function isRemainCheese() {
    for (let row = 1; row < masterRow - 1; row++) {
        for (let col = 1; col < masterCol - 1; col++) {
            if (input[row][col] === '1') return true;
        }
    }
    return false;
}

// 2. 빈 공간 탐색
function searchEmptySpace() {
    const queue = [[0, 0]];
    input[0][0] = '2+';
    while (queue.length !== 0) {
        const [row, col] = queue.shift();
        if (row >= 1) {
            if (input[row - 1][col] === '0' || input[row - 1][col] === '2') {
                queue.push([row - 1, col]);
                input[row - 1][col] = '2+';
            }
        }
        if (col >= 1) {
            if (input[row][col - 1] === '0' || input[row][col - 1] === '2') {
                queue.push([row, col - 1]);
                input[row][col - 1] = '2+';
            }
        }
        if (row < masterRow - 1) {
            if (input[row + 1][col] === '0' || input[row + 1][col] === '2') {
                queue.push([row + 1, col]);
                input[row + 1][col] = '2+';
            }
        }
        if (col < masterCol - 1) {
            if (input[row][col + 1] === '0' || input[row][col + 1] === '2') {
                queue.push([row, col + 1]);
                input[row][col + 1] = '2+';
            }
        }
    }

    for (let row = 0; row < masterRow; row++) {
        for (let col = 0; col < masterCol; col++) {
            if (input[row][col] === '2+') input[row][col] = '2';
        }
    }
}

// 3. 녹아야 할 치즈 설정 후 지우기
function meltCheese() {
    for (let row = 1; row < masterRow - 1; row++) {
        for (let col = 1; col < masterCol - 1; col++) {
            if (input[row][col] === '1') {
                let airAmount = 0;
                if (input[row - 1][col] === '2') airAmount++;
                if (input[row + 1][col] === '2') airAmount++;
                if (input[row][col - 1] === '2') airAmount++;
                if (input[row][col + 1] === '2') airAmount++;

                if (airAmount >= 2) input[row][col] = '1+';
            }
        }
    }

    for (let row = 1; row < masterRow - 1; row++) {
        for (let col = 1; col < masterCol - 1; col++) {
            if (input[row][col] === '1+') input[row][col] = '2';
        }
    }
}