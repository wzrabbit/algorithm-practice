const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n").map(Number);
const sum = (input[0] * input[1] * input[2]).toString();
let times = new Array(10).fill(0);

for (let i = 0; i < sum.length; i++) {
    times[sum[i]] += 1;
}

console.log(times.join("\n"));