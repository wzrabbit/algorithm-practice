const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split(" ").map(Number).sort((a, b) => b - a);
const numA = input[0];
const numB = input[1];
let div;
let mul;

// 최대공약수 구하기
// 유클리드 호제법을 이용한다면, 매우 큰 수의 최대공약수도 빠르게 구할 수 있다
let board = [numA, numB];
let divisorFound = false;
while (divisorFound === false) {
  board[board.length] = board[board.length - 2] % board[board.length - 1];
  if (board[board.length - 1] === 0) divisorFound = true;
}
div = board[board.length - 2]; // 리스트의 마지막에서 두 번째 수 = 최대공약수

// 최소공배수 구하기
mul = numA * numB / div;

console.log(div + "\n" + mul);
