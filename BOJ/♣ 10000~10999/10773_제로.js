const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n").map(Number);
input.shift();

let stack = [];

for (let i = 0; i < input.length; i++) {
  if (input[i] !== 0) {
    stack.push(input[i]);
  }
  else {
    stack.pop();
  }
}

let sum = 0;
for (let i = 0; i < stack.length; i++) {
  sum += stack[i];
}

console.log(sum);