let input = require('fs').readFileSync('/dev/stdin').toString().trim();
input = input.replace(/\(\)/g, 'R');
let stack = [];
let stick = 0;

for (let i = 0; i < input.length; i++) {
  if (input[i] === '(') {
    stack.push('(');
    stick++;
  }
  else if (input[i] === ')') stack.pop();
  else stick += stack.length;
}

console.log(stick);