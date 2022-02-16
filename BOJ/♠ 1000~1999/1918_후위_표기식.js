const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('');
let stack = [];
let printer = '';

for (let i = 0; i < input.length; i++) {
  if (/[A-Z]/.test(input[i])) printer += input[i];
  else if (input[i] === '(') stack.push('(');
  else if (input[i] === ')') {
    while (stack[stack.length - 1] !== '(') printer += stack.pop();
    stack.pop();
  }
  else if (input[i] === '*' || input[i] === '/') {
    while (stack.length !== 0 && (stack[stack.length - 1] === '*' || stack[stack.length - 1] === '/')) printer += stack.pop();
    stack.push(input[i]);
  }
  else if (input[i] === '+' || input[i] === '-') {
    while (stack.length !== 0 && (stack[stack.length - 1] !== '(')) printer += stack.pop();
    stack.push(input[i]);
  }
}

let len = stack.length;
for (let i = 0; i < len; i++) {
  printer += stack.pop();
}

console.log(printer);