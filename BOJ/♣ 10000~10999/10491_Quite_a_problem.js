const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

for (let i = 0; i < input.length; i++) {
    if (input[i].match(/problem/i)) console.log("yes");
    else console.log("no");
}