const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split(" ");
let resultNumber = [];

for (let i = 0; i <= 1; i++) {
    let num = input[i];
    num = num.split("");
    let temp = num[0];
    num[0] = num[2];
    num[2] = temp;
    resultNumber.push(parseInt(num.join("")));
}

console.log(resultNumber[0] > resultNumber[1] ? resultNumber[0] : resultNumber[1]); 