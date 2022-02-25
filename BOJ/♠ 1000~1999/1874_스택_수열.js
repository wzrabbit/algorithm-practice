const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let stack = [];
let poppedCount = 0;
let currentPushNumber = 1;
let repeat = parseInt(input[0]);
let searchIndex = 1;
let result = "";

while (poppedCount < repeat) {
    // -
    if (input[searchIndex] == stack[stack.length - 1]) {
        searchIndex++;
        stack.pop();
        poppedCount++;
        result += "-\n";
    }
    // NO
    else if (currentPushNumber > repeat) {
        result = "NO";
        break;
    }
    // +
    else {
        stack.push(currentPushNumber);
        currentPushNumber++;
        result += "+\n";
    }
}

console.log(result);
