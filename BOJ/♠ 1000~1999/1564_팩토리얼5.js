const fs = require("fs");
const input = parseInt(fs.readFileSync("/dev/stdin").toString().trim());
let result = 1;

for (let i = 1; i <= input; i++) {
    result *= i;
    while (result % 10 === 0) {
        result /= 10;
    }
    result = result % 1000000000000;
}

result = (result % 100000).toString();

while (result.length != 5) {
    result = "0" + result;
}

console.log(result);