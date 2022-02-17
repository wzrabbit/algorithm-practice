const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split(" ").map(Number);
const mainNumber = input[0];
const order = input[1];
let divideNumber = 1;
let divisor = [];

while (divideNumber <= mainNumber) {
    if (mainNumber % divideNumber === 0) {
        divisor.push(mainNumber / divideNumber);
    }
    divideNumber++;
}

if (divisor.length >= order) {
    divisor.sort((a, b) => a - b);
    console.log(divisor[order - 1]);
}
else { console.log(0); }