const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let score = input.toString().split(" ").map(Number);
let maxScore = Math.max(...score); 

for (let i = 0; i < score.length; i++) {
    score[i] = score[i] / maxScore * 100;
}

const avg = score.reduce((a, b) => a + b, 0) / score.length;
console.log(avg);
