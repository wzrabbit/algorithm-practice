const input = require("fs").readFileSync("/dev/stdin").toString().trim().split(" ");
const start = parseInt(input[0]);
const end = parseInt(input[1]);
let sigma = 0;

if (start <= end) console.log((start + end) * (end - start + 1) / 2);
else console.log((start + end) * (start - end + 1) / 2);