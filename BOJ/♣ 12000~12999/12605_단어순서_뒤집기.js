const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let result = "";
let stack = [];

for (let i = 0; i < input.length; i++) {
  input[i] = input[i].split(" ");
}

for (let i = 0; i < input.length; i++) {
  for (let j = 0; j < input[i].length; j++) {
    stack.push(input[i][j]);
  }
  result += "Case #" + (i + 1) + ": ";
  for (let j = 0; j < input[i].length; j++) {
    result += stack.pop(input[i][j]) + " ";
  }
  result.slice(0, -1);
  result += "\n";
}

console.log(result);