const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();

input = new Set(input);
input = Array.from(input);
input = input.sort();

for (let i = 1; i <= 50; i++) {
    for (let j = 0; j < input.length; j++) {
        if (input[j].length === i) {
            console.log(input[j]);
        }
    }
}