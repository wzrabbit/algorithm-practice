const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();

const numbers = input.toString().split(" ").map(Number);
console.log(Math.min(...numbers) + " " + Math.max(...numbers));