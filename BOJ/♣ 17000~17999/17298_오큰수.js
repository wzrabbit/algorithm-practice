let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const len = parseInt(input[0]);
input = input[1].split(' ').map(Number);
let result = new Array(len).fill(-1);

let stack = [0];
for (let i = 1; i < len; i++) {
    if (input[stack[stack.length - 1]] < input[i]) {
        while (input[stack[stack.length - 1]] < input[i]) {
            result[stack.pop()] = input[i];
        }
    }
    stack.push(i);
}

console.log(result.join(' '));