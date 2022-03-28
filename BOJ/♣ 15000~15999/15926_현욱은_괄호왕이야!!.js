const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')[1].split('');
let check = new Array(input.length).fill(0);
let current = max = 0;
const stack = [];

for (let i = 0; i < input.length; i++) {
    if (input[i] === '(') stack.push(i);
    else if (stack.length !== 0) {
        check[i] = check[stack.pop()] = 1;
    }
}

for (let i = 0; i < input.length; i++) {
    if (check[i] === 1) current++;
    else {
        if (current > max) max = current;
        current = 0;
    }
}
if (current > max) max = current;

console.log(max);