const [N, M] = require("fs")
  .readFileSync(0, "utf-8")
  .toString()
  .trim()
  .split(" ")
  .map(BigInt);

console.log((N / M).toString());
console.log((N % M).toString());
