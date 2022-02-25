let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();

console.log(input.charCodeAt(0));