let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const row = parseInt(input[0].split(' ')[0]);
const col = parseInt(input[0].split(' ')[1]);
const trash = parseInt(input[0].split(' ')[2]);
input.shift();
let count = 0;
let biggestTrash = 0;

let floor = Array(row);
for (let i = 0; i < row; i++) {
    floor[i] = Array(col).fill('.');
}

for (let i = 0; i < trash; i++) {
    let data = input[i].split(' ');
    floor[data[0] - 1][data[1] - 1] = '#';
}

for (let i = 0; i < row; i++) {
    for (let j = 0; j < col; j++) {
        if (floor[i][j] === '#') {
            count = 0;
            dfs(i, j, row, col);
            if (count > biggestTrash) biggestTrash = count;
        }
    }
}

console.log(biggestTrash);

function dfs(row, col, maxRow, maxCol) {
    floor[row][col] = 'X';
    count++;

    if (row > 0) {
        if (floor[row - 1][col] === '#') dfs(row - 1, col, maxRow, maxCol);
    }
    if (col > 0) {
        if (floor[row][col - 1] === '#') dfs(row, col - 1, maxRow, maxCol);
    }
    if (row < maxRow - 1) {
        if (floor[row + 1][col] === '#') dfs(row + 1, col, maxRow, maxCol);
    }
    if (col < maxCol - 1) {
        if (floor[row][col + 1] === '#') dfs(row, col + 1, maxRow, maxCol);
    }
}
