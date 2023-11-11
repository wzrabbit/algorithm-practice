const words = require('fs')
  .readFileSync(0, 'utf-8')
  .replace('')
  .match(/[A-z]+/g);

const getGCD = (a, b) => {
  if (a % b === 0) {
    return b;
  }

  return getGCD(b, a % b);
};

let normalWordCount = 0;
let bullshitCount = 0;
const spokenWords = new Set();

words.forEach((word) => {
  if (word === 'BULLSHIT') {
    normalWordCount += spokenWords.size;
    bullshitCount += 1;
    spokenWords.clear();
  } else {
    spokenWords.add(word.toLowerCase());
  }
});

const gcd = getGCD(bullshitCount, normalWordCount);
console.log(`${normalWordCount / gcd} / ${bullshitCount / gcd}`);
