const fs = require("fs");
const input = parseInt(fs.readFileSync("/dev/stdin").toString().trim());
let result = "";

for (let i = 0; i < input; i++) {
    for (let j = 0; j <= i; j++) {
        result += "*";
    }
    if (!(input - i === 1)) result += "\n";
}

console.log(result);