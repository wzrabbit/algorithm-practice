const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const repeat = input[0].split(" ")[0];
const num = input[0].split(" ")[1];
const numbers = input[1].split(" ").map(Number);
let result = [];

for (let i = 0; i < repeat; i++) {
    if (numbers[i] < num) result.push(numbers[i]);
}

console.log(result.join(" "));