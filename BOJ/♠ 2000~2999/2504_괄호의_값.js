const input = require('fs').readFileSync('/dev/stdin').toString().trim();
let stack = [];
let prev = '';
let score = 0;
let current = 1;
let isValid = true;

for (let i = 0; i < input.length; i++) {
    switch (input[i]) {
        case '(':
            stack.push('(');
            current *= 2;
            prev = '(';
            break;
        case '[':
            stack.push('[');
            current *= 3;
            prev = '[';
            break;
        case ')':
            if (stack.length === 0 || stack.pop() !== '(') {
                isValid = false;
                score = 0;
                break;
            }
            if (prev === '(')
                score += current;
            current /= 2;
            prev = ')';
            break;
        case ']':
            if (stack.length === 0 || stack.pop() !== '[') {
                isValid = false;
                score = 0;
                break;
            }
            if (prev === '[')
                score += current;
            current /= 3;
            prev = ']';
            break;
    }

    if (!isValid)
        break;
}

if (stack.length !== 0)
    score = 0;

console.log(score);