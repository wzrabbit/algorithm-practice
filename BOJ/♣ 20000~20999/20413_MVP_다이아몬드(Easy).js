const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let months = parseInt(input[0]);
let rankScores = input[1].split(" ").map(Number);
let maxRankScores = {
    "B": rankScores[0] - 1, "S": rankScores[1] - 1,
    "G": rankScores[2] - 1, "P": rankScores[3] - 1
};
let ranks = input[2];
let previousMoney = 0;
let totalMoney = 0;

for (let i = 0; i < months; i++) {
    let currentMoney = (ranks[i] === "D") ? rankScores[3] : maxRankScores[ranks[i]] - previousMoney;
    totalMoney += currentMoney;
    previousMoney = currentMoney;
}

console.log(totalMoney);
