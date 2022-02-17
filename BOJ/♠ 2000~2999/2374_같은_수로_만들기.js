const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((x) => parseInt(x));
const len = input[0];
let stack = [];
let used = 0;

for (let i = 1; i <= len; i++) {
  if (stack.length === 0 || stack[stack.length - 1] >= input[i]) stack.push(input[i]);
  else {
    used += input[i] - stack[stack.length - 1];
    while (stack.length > 0 && stack[stack.length - 1] < input[i]) stack.pop();
    stack.push(input[i]);
  }
}

used += stack[0] - stack[stack.length - 1];
console.log(used);