let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let task = parseInt(input[0]);
let score = 0;
let stack = [];

for (let i = 1; i <= task; i++) {
    if (input[i][0] === '1') {
        stack.push(input[i].replace('1 ', '').split(' ').map(Number));
    }

    if (stack.length !== 0) {
        stack[stack.length - 1][1] -= 1;
        if (stack[stack.length - 1][1] === 0) score += stack.pop()[0];
    }
}

console.log(score);
