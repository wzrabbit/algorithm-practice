const input = require("fs").readFileSync("/dev/stdin").toString().trim().split(" ").map(Number);
const start = input[0];
const end = input[1];
const searchEnd = Math.sqrt(end);
let board = [...Array(end + 1).keys()];
let result = "";
board[1] = 0;

for (let i = 2; i <= searchEnd; i++) {
    if (board[i] === 0) continue;
    else {
        for (let j = i * 2; j <= end; j += i) {
            board[j] = 0;
        }
    }
}

for (let i = start; i <= end; i++) {
    if (board[i] !== 0) result += i + "\n";
}

result = result.slice(0, -1);
console.log(result);
