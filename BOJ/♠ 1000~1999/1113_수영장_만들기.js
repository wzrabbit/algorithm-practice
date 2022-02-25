let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [row, col] = input[0].split(' ').map((x) => parseInt(x));
let poolSample = [];
let total = 0;

for (let i = 1; i <= row; i++) {
    poolSample.push(input[i].split('').map((x) => parseInt(x)));
}

let pool;
for (let lv = 2; lv <= 9; lv++) {
    pool = poolSample.map((x) => x.slice());
    let count = 0;

    for (let r = 0; r < row; r++) {
        bfs(r, 0, lv);
        bfs(r, col - 1, lv);
    }

    for (let c = 1; c < col - 1; c++) {
        bfs(0, c, lv);
        bfs(row - 1, c, lv);
    }

    for (let r = 0; r < row; r++) {
        for (let c = 0; c < col; c++) {
            if (pool[r][c] !== 'X' && pool[r][c] < lv) count++;
        }
    }
    total += count;
}

console.log(total);

function bfs(startRow, startCol, level) {
    if (pool[startRow][startCol] >= level) return;
    let queue = [[startRow, startCol]];
    pool[startRow][startCol] = 'X';
    let index = 0;
    let dr = [-1, 1, 0, 0];
    let dc = [0, 0, -1, 1];

    while (index < queue.length) {
        let [r_, c_] = queue[index];
        index++;
        for (let i = 0; i <= 3; i++) {
            let r = r_ + dr[i];
            let c = c_ + dc[i];

            if (r >= 0 && r < row && c >= 0 && c < col) {
                if (pool[r][c] !== 'X' && pool[r][c] < level) {
                    pool[r][c] = 'X';
                    queue.push([r, c]);
                }
            }
        }
    }
}