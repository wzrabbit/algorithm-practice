const fs = require("fs");
let input = parseInt(fs.readFileSync("/dev/stdin"));
let num = 1;
let distance = 1;

while (num < input) {
  num += distance * 6;
  distance++;
}

console.log(distance);
