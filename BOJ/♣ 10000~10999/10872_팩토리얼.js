const fs = require("fs");
const input = parseInt(fs.readFileSync("/dev/stdin").toString().trim());

console.log(factorial(input));

// 재귀함수를 이용한 팩토리얼 계산 함수
function factorial(num) {
    if (num <= 1) return 1;
    else return num * factorial(num - 1);
}