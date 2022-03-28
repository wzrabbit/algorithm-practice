const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const num = parseInt(input[0]);
let board = new Array(366).fill(0);
let total = 0;
let count = 0;
let max_ = 0;

const doTask = (start, end) => {
    for (let i = start; i <= end; i++) {
        board[i]++;
    }
}

for (let i = 1; i <= num; i++) {
    const [start, end] = input[i].split(' ').map((x) => parseInt(x));
    doTask(start, end);
}

for (let i = 1; i <= 365; i++) {
    if (board[i] === 0) {
        total += max_ * count;
        max_ = 0;
        count = 0;
    }
    else {
        max_ = Math.max(board[i], max_);
        count++;
    }
}
total += max_ * count;

console.log(total);