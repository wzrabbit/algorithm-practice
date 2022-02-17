const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split(" ").map(Number);
const climbPerDay = input[0] - input[1];
const lastClimb = input[0];
const climbExceptLast = input[2] - lastClimb;

console.log(Math.ceil(climbExceptLast / climbPerDay) + 1);