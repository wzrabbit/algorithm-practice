const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split(" ").map(Number);
let n = input[0];
let r = input[1];

console.log(factorial(n) / (factorial(r) * factorial(n - r)));

// 재귀함수를 이용한 팩토리얼 계산 함수
function factorial(num) {
    if (num <= 1) return 1;
    else return num * factorial(num - 1);
}