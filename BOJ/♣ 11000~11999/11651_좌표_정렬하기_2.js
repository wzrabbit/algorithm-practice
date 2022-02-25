const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let arr = input;
arr.shift();
let result = "";

for (let i = 0; i < arr.length; i++) {
    arr[i] = arr[i].split(" ").map(Number);
}

arr.sort((a, b) => {
    if (a[1] === b[1]) return a[0] - b[0];
    else return a[1] - b[1];
});

for (let i = 0; i < arr.length; i++) {
    result += arr[i][0] + " " + arr[i][1] + "\n";
}

console.log(result);