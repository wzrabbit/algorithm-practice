const CHARCODE_GAP = 65;
const CYCLE_SIZE = 26;

const getLetterScore = (matchedLetter) => {
  return (
    (matchedLetter.match(/\+/g) || []).length -
    (matchedLetter.match(/-/g) || []).length
  );
};

const getConvertedLetter = (letter, score) => {
  return String.fromCharCode(
    ((letter.charCodeAt() - CHARCODE_GAP + score + CYCLE_SIZE * 10000) %
      CYCLE_SIZE) +
      CHARCODE_GAP
  );
};

const interpretLetter = (matchedLetter) => {
  const letter = matchedLetter.match(/[A-Z?]/)[0];
  const score = getLetterScore(matchedLetter);

  if (letter === "?") return "?";
  return getConvertedLetter(letter, score);
};

const solveCipher = (cipher) => {
  while (cipher.includes("[")) {
    cipher = cipher.replace(/\[[^[\]]*?\]/g, (matched) => {
      const solvedCipher = solveCipher(matched.slice(1, matched.length - 1));
      return solvedCipher.split("").reverse().join("");
    });
  }

  while (cipher.includes("+") || cipher.includes("-")) {
    cipher = cipher.replace(/[+-]+[A-Z?]/g, (matched) => {
      return interpretLetter(matched);
    });
  }

  return cipher;
};

const input = require("fs")
  .readFileSync(0, "utf-8")
  .toString()
  .trim()
  .split("\n");

let printer = "";

for (let i = 0; i < input.length - 1; i++) {
  const finalCipher = solveCipher(input[i]).replace(/\?/g, "A");
  printer += `${finalCipher}\n`;
}

console.log(printer);
