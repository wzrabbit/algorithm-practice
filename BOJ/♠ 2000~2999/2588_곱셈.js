let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");
let num1 = [Number(input[0][0]), Number(input[0][1]), Number(input[0][2])];
let num2 = [Number(input[1][0]), Number(input[1][1]), Number(input[1][2])];
// [0] : 백의 자리, [1] : 십의 자리, [2] : 일의 자리

let answer3 = (num1[2] * num2[2] + num1[1] * num2[2] * 10 + num1[0] * num2[2] * 100);
let answer4 = (num1[2] * num2[1] + num1[1] * num2[1] * 10 + num1[0] * num2[1] * 100);
let answer5 = (num1[2] * num2[0] + num1[1] * num2[0] * 10 + num1[0] * num2[0] * 100);
let answer6 = answer3 + answer4 * 10 + answer5 * 100;

console.log(answer3 + "\n" + answer4 + "\n" + answer5 + "\n" + answer6);