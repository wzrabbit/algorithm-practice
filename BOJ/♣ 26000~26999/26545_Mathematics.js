const [, ...numbers] = require("fs")
  .readFileSync(0, "utf-8")
  .split("\n")
  .map(Number);

const sum = numbers.reduce((acc, cur) => acc + cur);
console.log(sum);
