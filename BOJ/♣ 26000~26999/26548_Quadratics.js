const [, ...input] = require("fs").readFileSync(0, "utf-8").trim().split("\n");
let printer = "";

input.forEach((testcase) => {
  const [A, B, C] = testcase.split(" ").map(Number);
  const plusAnswer = ((-B + Math.sqrt(B ** 2 - 4 * A * C)) / (2 * A)).toFixed(3);
  const minusAnswer = ((-B - Math.sqrt(B ** 2 - 4 * A * C)) / (2 * A)).toFixed(3);
  printer += `${plusAnswer}, ${minusAnswer}\n`;
});

console.log(printer);
