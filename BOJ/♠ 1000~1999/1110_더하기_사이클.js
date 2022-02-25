const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
if (input.length === 1) {
    input = "0" + input;
}
input = [input[0], input[1]].map(Number);

let num = [input[0], input[1]];
let count = 0;
let temp;

do {
    temp = num[1];
    num[1] = (num[0] + num[1]) % 10;
    num[0] = temp;
    count++;
} while (num[0] !== input[0] || num[1] !== input[1])

console.log(count);