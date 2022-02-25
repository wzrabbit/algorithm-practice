let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let [len, chance] = input[0].split(' ').map(Number);
input = input[1].split('').map(Number);

let stack = [input[0]];

for (let i = 1; i < len; i++) {
    if (stack[stack.length - 1] < input[i] && chance >= 1) {
        while (stack[stack.length - 1] < input[i] && chance >= 1) {
            stack.pop();
            chance--;
        }
    }
    stack.push(input[i]);
}

while (chance > 0) {
    stack.pop();
    chance--;
}

console.log(stack.join(''));