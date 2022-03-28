const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let result = "";

for (let i = 0; i < input.length; i++) {
    let data = input[i].split(" ").map(Number);
    result += (data[0] + data[1]).toString() + "\n";
}

result.slice(0, -1);
console.log(result);