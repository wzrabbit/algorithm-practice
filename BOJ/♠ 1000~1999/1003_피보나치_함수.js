const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n").map(Number);
let cases = input[0];
let result = "";

for (let i = 1; i <= cases; i++) {
  let num = input[i];
  let board = new Array(41);
  board[0] = 1;
  board[1] = 0;

  for (let j = 1; j <= num; j++) {
    board[j + 1] = board[j - 1] + board[j];
  }

  result += board[num] + " " + board[num + 1] + "\n";
}

console.log(result);
