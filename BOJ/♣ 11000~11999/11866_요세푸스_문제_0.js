const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split(" ");
const number = parseInt(input[0]);
const kill = parseInt(input[1]);
let table = [...Array(number + 1).keys()];
let killList = [];
let startIndex = 1;

for (let i = 0; i < number; i++) {
  for (let i = 0; i < kill - 1; i++) {
    table[table.length] = table[startIndex];
    startIndex++;
  }
  killList.push(table[startIndex]);
  startIndex++;
}

console.log("<" + killList.join(", ") + ">");