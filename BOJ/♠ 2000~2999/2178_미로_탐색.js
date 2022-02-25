let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const maxRow = parseInt(input[0].split(' ')[0]);
const maxCol = parseInt(input[0].split(' ')[1]);
input.shift();

for (let i = 0; i < input.length; i++) {
    input[i] = input[i].split('');
}

console.log(bfs());

function bfs() {
    let queue = [[0, 0, 1]];
    input[0][0] = '2';

    while (true) {
        current = queue.shift();
        let row = current[0];
        let col = current[1];
        let dis = current[2];

        if (row === maxRow - 1 && col === maxCol - 1) {
            return dis;
        }

        if (row > 0) {
            if (input[row - 1][col] === '1') {
                queue.push([row - 1, col, dis + 1]);
                input[row - 1][col] = '2';
            }
        }

        if (col > 0) {
            if (input[row][col - 1] === '1') {
                queue.push([row, col - 1, dis + 1]);
                input[row][col - 1] = '2';
            }
        }

        if (row < maxRow - 1) {
            if (input[row + 1][col] === '1') {
                queue.push([row + 1, col, dis + 1]);
                input[row + 1][col] = '2';
            }
        }

        if (col < maxCol - 1) {
            if (input[row][col + 1] === '1') {
                queue.push([row, col + 1, dis + 1]);
                input[row][col + 1] = '2';
            }
        }
    }
}