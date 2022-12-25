const getNextLetter = (currentLetter) => {
  const currentLetterCharCode = currentLetter.charCodeAt();
  const nextLetterCharCode = ((currentLetterCharCode - 64) % 26) + 65;
  const nextLetter = String.fromCharCode(nextLetterCharCode);
  return nextLetter;
};

const [, ...input] = require("fs").readFileSync(0, "utf-8").trim().split("\n");
let printer = "";

input.forEach((testcase) => {
  let [scale, letter] = testcase.split(" ");
  scale = Number(scale);

  for (let index = 1; index <= scale; index++) {
    printer += letter.repeat(index) + "\n";
    letter = getNextLetter(letter);
  }
  printer += "\n";
});

console.log(printer);
