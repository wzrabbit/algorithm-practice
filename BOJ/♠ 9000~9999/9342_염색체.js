const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();

for (let i = 0; i < input.length; i++) {
    if (input[i].match(/^[ABCDEF]?A+F+C+[ABCDEF]?$/)) console.log("Infected!");
    else console.log("Good");
}