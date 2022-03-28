const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const dataLength = input[0].split(" ")[0];
const searchLength = input[0].split(" ")[1];

let passwordMap = new Map();
let result = "";
let i = 1;

for (i; i <= dataLength; i++) {
    let currentData = input[i].split(" ");
    passwordMap.set(currentData[0], currentData[1]);
}

for (i; i <= parseInt(dataLength) + parseInt(searchLength); i++) {
    result += passwordMap.get(input[i]) + "\n";
}

console.log(result);
