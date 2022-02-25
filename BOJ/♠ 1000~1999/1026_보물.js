const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const length = input[0];
let arrayA = input[1].split(" ").map(Number);
let arrayB = input[2].split(" ").map(Number);
let result = 0;

arrayA.sort((a, b) => a - b);
arrayB.sort((a, b) => b - a);

for (let i = 0; i < length; i++) {
    result += arrayA[i] * arrayB[i];
}

console.log(result);