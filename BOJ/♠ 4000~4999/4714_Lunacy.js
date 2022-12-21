const input = require("fs")
  .readFileSync(0, "utf-8")
  .trim()
  .split("\n")
  .map((x) => parseFloat(x));
input.pop();

let printer = "";

input.forEach((testcase) => {
  const originalWeigh = testcase.toFixed(2);
  const calculatedWeigh = (testcase * 0.167).toFixed(2);
  printer += `Objects weighing ${originalWeigh} on Earth will weigh ${calculatedWeigh} on the moon.\n`;
});

console.log(printer);
