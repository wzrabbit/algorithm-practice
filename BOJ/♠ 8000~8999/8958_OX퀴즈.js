const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let score = 0;

for (let i = 0; i < input.length; i++) {
    let data = input[i];
    let combo = 0;
    for (let j = 0; j < data.length; j++) {
        if (data[j] === "O") {
            combo += 1;
            score += combo;
        }
        else {
            combo = 0;
        }

    }
    console.log(score);
    score = 0;
}