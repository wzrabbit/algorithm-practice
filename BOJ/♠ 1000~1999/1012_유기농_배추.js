const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const cases = parseInt(input[0]);
input.shift();
let index = 0;
let result = '';

for (let h = 0; h < cases; h++) {
    const col = parseInt(input[index].split(' ')[0]);
    const row = parseInt(input[index].split(' ')[1]);
    const cab = parseInt(input[index].split(' ')[2]);
    let farm = [];
    let worm = 0;
    for (let i = 0; i < row; i++) {
        farm[i] = Array(col).fill(0);
    }

    for (let i = 0; i < cab; i++) {
        let newCab = input[index + 1 + i].split(' ');
        farm[newCab[1]][newCab[0]] = 1;
    }
    for (j = 0; j < row; j++) {
        for (k = 0; k < col; k++) {
            if (farm[j][k] === 1) {
                worm++;
                dfs(j, k, farm, row, col);
            }
        }
    }

    result += worm + '\n';
    index += cab + 1;
}

result = result.slice(0, -1);
console.log(result);

function dfs(row, col, farm, maxRow, maxCol) {
    farm[row][col] = 'X';

    if (row > 0) {
        if (farm[row - 1][col] === 1) dfs(row - 1, col, farm, maxRow, maxCol);
    }
    if (col > 0) {
        if (farm[row][col - 1] === 1) dfs(row, col - 1, farm, maxRow, maxCol);
    }
    if (row < maxRow - 1) {
        if (farm[row + 1][col] === 1) dfs(row + 1, col, farm, maxRow, maxCol);
    }
    if (col < maxCol - 1) {
        if (farm[row][col + 1] === 1) dfs(row, col + 1, farm, maxRow, maxCol);
    }
}
