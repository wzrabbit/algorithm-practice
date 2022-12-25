const input = require("fs").readFileSync(0, "utf-8").trim();
const overTwoLetters = (input.match(/(.)\1+/g) || [" "]).map(
  (frag) => frag.length - 1
);
const answer = overTwoLetters.reduce((acc, cur) => acc + cur);
console.log(answer);
