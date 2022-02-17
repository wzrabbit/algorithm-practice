const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split(" ").map(Number);
let h = input[0];
let m = input[1];

m -= 45;

if (m < 0) {
    h--; m += 60;
}

if (h < 0) {
    h = 23;
}

console.log(h + " " + m)