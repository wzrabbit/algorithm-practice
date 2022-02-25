const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let result = "";

for (let i = 0; i < input.length; i++) {
    let data = input[i].split(" ").map(Number);
    result += "Case #" + (i + 1) + ": " + (data[0] + data[1]) + "\n";
}

console.log(result);