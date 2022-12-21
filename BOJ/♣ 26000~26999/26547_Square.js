const makeQuilt = (word) => {
  const len = word.length;
  let quilt = "";

  if (len === 1) {
    return word;
  }

  quilt += word + "\n";
  for (let index = 0; index < len - 2; index++) {
    quilt +=
      word[index + 1] + " ".repeat(len - 2) + word[len - index - 2] + "\n";
  }
  quilt += word.split("").reverse().join("") + "\n";

  return quilt;
};

const [, ...words] = require("fs").readFileSync(0, "utf-8").trim().split("\n");
let printer = "";

words.forEach((currentWord) => {
  printer += makeQuilt(currentWord);
});

console.log(printer);
