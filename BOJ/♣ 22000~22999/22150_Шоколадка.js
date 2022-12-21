const [_, ...input] = require("fs")
  .readFileSync(0, "utf-8")
  .toString()
  .trim()
  .split("\n");
let printer = "";

input.forEach((testCase) => {
  const [size, ...widthData] = testCase.split(" ").map(Number);
  let isStolen = false;

  for (let i = 0; i < size * 2; i += 2) {
    if (widthData[i] + widthData[i + 1] < size) {
      isStolen = true;
      break;
    }
  }

  printer += isStolen ? "yes\n" : "no\n";
});

console.log(printer);
