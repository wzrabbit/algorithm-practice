const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const repeat = parseInt(input[0]);
const numberArray = input[1].split(" ").map(Number);
let count = 0;

for (let i = 0; i < repeat; i++) {
    if (checkPrimeNumber(numberArray[i])) count++;
}

console.log(count);

// 소수 판정 함수
function checkPrimeNumber(num) {
    let divisorList = [];
    for (let i = 1; i <= num; i++) {
        if (num % i === 0) divisorList.push(i);
        if (divisorList.length > 2) return false;
    }
    if (divisorList.length === 2) return true;
    else return false;
}