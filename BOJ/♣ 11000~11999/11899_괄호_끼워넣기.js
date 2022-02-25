const input = require('fs').readFileSync('/dev/stdin').toString().trim();

let stack = [];
let need = 0;
for (let i = 0; i < input.length; i++) {
  if (input[i] === '(') stack.push('(');
  else if (stack.length === 0) need++;
  else stack.pop();
}
need += stack.length;

console.log(need);