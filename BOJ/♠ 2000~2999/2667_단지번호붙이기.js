let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const width = parseInt(input[0]);
input.shift();
let count = 0;
let buildings = [];

for (let i = 0; i < width; i++) {
    input[i] = input[i].split('');
}

for (let i = 0; i < width; i++) {
    for (let j = 0; j < width; j++) {
        if (input[i][j] === '1') {
            count = 0;
            dfs(i, j);
            buildings.push(count);
        }
    }
}

buildings.sort((a, b) => a - b);
console.log(buildings.length);

buildings = buildings.join('\n');
console.log(buildings);

function dfs(row, col) {
    input[row][col] = 'X';
    count++;

    if (row > 0) {
        if (input[row - 1][col] === '1') dfs(row - 1, col);
    }
    if (col > 0) {
        if (input[row][col - 1] === '1') dfs(row, col - 1);
    }
    if (row < width - 1) {
        if (input[row + 1][col] === '1') dfs(row + 1, col);
    }
    if (col < width - 1) {
        if (input[row][col + 1] === '1') dfs(row, col + 1);
    }
}