const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

for (let i = 0; i < input.length; i++) {
    let data = input[i].split(" ").map(Number);
    console.log(data[0] + data[1]);
}