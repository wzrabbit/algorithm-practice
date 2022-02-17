const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n").map(Number);
input.shift();
let result = "";

input.sort((a, b) => a - b);

for (let i = 0; i < input.length; i++) {
    result += input[i] + "\n";
}
result.slice(0, -1);

console.log(result);