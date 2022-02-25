const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let result = "";

for (let i = 0; i < input.length; i++) {
    input[i] = input[i].split(" ").map(Number);
}

for (let i = 0; i < input.length; i++) {
    let height = input[i][0];
    let width = input[i][1];
    let num = input[i][2];

    let first = num % height === 0 ? height : num % height;
    let l = Math.floor((num - 1) / height) + 1;
    let last = (l < 10) ? "0" + l : l;

    result += String(first) + last + "\n";
}

console.log(result);