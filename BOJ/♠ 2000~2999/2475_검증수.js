const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split(" ").map(Number);
let sum = 0;

for (let i = 0; i < input.length; i++) {
    sum += input[i] ** 2;
}
sum = sum % 10;

console.log(sum);