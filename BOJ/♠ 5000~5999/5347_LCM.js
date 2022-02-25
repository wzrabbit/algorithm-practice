const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const repeat = input[0];
let result = "";

for (let i = 1; i <= repeat; i++) {
    input[i] = input[i].split(" ").map(Number).sort((a, b) => b - a);
}

for (let i = 1; i <= repeat; i++) {
    const numA = input[i][0];
    const numB = input[i][1];
    let div;
    let mul;

    let board = [numA, numB];
    let divisorFound = false;
    while (divisorFound === false) {
        board[board.length] = board[board.length - 2] % board[board.length - 1];
        if (board[board.length - 1] === 0) divisorFound = true;
    }
    div = board[board.length - 2];
    mul = numA * numB / div;

    result += mul + "\n";
}

console.log(result);
