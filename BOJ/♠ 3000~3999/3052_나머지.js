const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n").map(Number);

for (let i = 0; i < 10; i++) {
    input[i] = input[i] % 42;
}

input = new Set(input);
input = new Array(...input);
if (input.length === 0) input.push(0);

console.log(input.length);