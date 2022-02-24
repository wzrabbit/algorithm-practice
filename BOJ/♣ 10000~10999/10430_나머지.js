let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split(" ");
let numA = Number(input[0]);
let numB = Number(input[1]);
let numC = Number(input[2]);

console.log((numA + numB) % numC);
console.log(((numA % numC) + (numB % numC)) % numC);
console.log((numA * numB) % numC);
console.log(((numA % numC) * (numB % numC)) % numC);