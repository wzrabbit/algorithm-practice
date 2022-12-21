const N = require("fs").readFileSync(0, "utf-8").trim();
let numberText = "";

for (let i = 1; i <= 100000; i++) {
  const currentNumber = i.toString();
  numberText += currentNumber;
}

console.log(numberText.indexOf(N) + 1);
