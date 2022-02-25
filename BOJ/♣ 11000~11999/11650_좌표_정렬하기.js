const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let arr = input;
arr.shift();

arr.sort((a, b) => {
  if (a.split(" ")[0] === b.split(" ")[0]) return a.split(" ")[1] - b.split(" ")[1];
  else return a.split(" ")[0] - b.split(" ")[0];
});

console.log(arr.join("\n"));