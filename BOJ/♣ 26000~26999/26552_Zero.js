const [, ...input] = require("fs")
  .readFileSync(0, "utf-8")
  .trim()
  .split("\n")
  .map(Number);

let printer = "";

input.forEach((testcase) => {
  let currentNumber = testcase + 1;

  while (currentNumber.toString().indexOf("0") !== -1) {
    currentNumber += 1;
  }

  printer += currentNumber + "\n";
});

console.log(printer);
