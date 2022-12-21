const [, ...input] = require("fs").readFileSync(0, "utf-8").trim().split("\n");
let printer = "";

input.forEach((testcase) => {
  let [word, leftIndex, rightIndex] = testcase.split(" ");
  leftIndex = Number(leftIndex);
  rightIndex = Number(rightIndex);

  printer += word.slice(0, leftIndex) + word.slice(rightIndex) + "\n";
});

console.log(printer);
