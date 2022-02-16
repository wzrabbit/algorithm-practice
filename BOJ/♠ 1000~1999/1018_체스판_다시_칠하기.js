const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const width = parseInt(input[0].split(" ")[0]);
const height = parseInt(input[0].split(" ")[1]);

let board = input;
board.shift();
let min = 64;

for (let i = 0; i <= width - 8; i++) {
    for (let j = 0; j <= height - 8; j++) {
        checkBoard(i, j);
    }
}

console.log(min);

function checkBoard(x, y) {
    let white = ["WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"];
    let whiteScore = 0;
    let blackScore = 0;
    for (let i = x; i < x + 8; i++) {
        for (let j = y; j < y + 8; j++) {
            if (board[i][j] !== white[i - x][j - y]) whiteScore++;
            else blackScore++;
        }
    }

    if (whiteScore < min) min = whiteScore;
    if (blackScore < min) min = blackScore;
}