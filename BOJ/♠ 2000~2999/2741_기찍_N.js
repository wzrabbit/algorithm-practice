const fs = require("fs");
const input = parseInt(fs.readFileSync("/dev/stdin"));
let result = "";

for (let i = input; i >= 1; i--) {
    result += i + "\n";
}

console.log(result);