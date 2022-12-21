const [R, C, N] = require("fs")
  .readFileSync(0, "utf-8")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

console.log(Math.ceil(R / N) * Math.ceil(C / N));
