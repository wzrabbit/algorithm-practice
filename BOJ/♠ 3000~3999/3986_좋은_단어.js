let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let count = 0;

for (let i = 1; i < input.length; i++) {
    let word = input[i];
    if (word.length % 2 === 1 || (word.match(/A/g) || 0).length % 2 === 1 || (word.match(/B/g) || 0).length % 2 === 1) continue;
    let stack = [];
    for (let i = 0; i < word.length; i++) {
        if (word[i] === 'A') {
            if (stack.length === 0 || stack[stack.length - 1] === 'B') stack.push('A');
            else stack.pop();
        }
        else {
            if (stack.length === 0 || stack[stack.length - 1] === 'A') stack.push('B');
            else stack.pop();
        }
    }
    if (stack.length === 0) count++;
}

console.log(count);