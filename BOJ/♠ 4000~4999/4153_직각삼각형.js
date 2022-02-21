const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.pop();

for (let i = 0; i < input.length; i++) {
    let lengthList = input[i].split(" ").sort((a, b) => a - b);
    if (lengthList[0] ** 2 + lengthList[1] ** 2 === lengthList[2] ** 2) {
        console.log("right");
    }
    else {
        console.log("wrong");
    }
}