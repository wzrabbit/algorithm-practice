const [_, ...sentences] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map((sentence) => sentence.toLowerCase());

let answer = '';

sentences.map((sentence, index) => {
  const alphabetCount = new Array(26).fill(0);

  for (let i = 0; i < sentence.length; i++) {
    const letter = sentence[i];

    if (letter < 'a' || letter > 'z') {
      continue;
    }

    const currentIndex = letter.charCodeAt() - 97;
    alphabetCount[currentIndex] += 1;
  }

  const minimumOccurrence = Math.min(...alphabetCount);

  if (minimumOccurrence === 0) {
    answer += `Case ${index + 1}: Not a pangram\n`;
  } else if (minimumOccurrence === 1) {
    answer += `Case ${index + 1}: Pangram!\n`;
  } else if (minimumOccurrence === 2) {
    answer += `Case ${index + 1}: Double pangram!!\n`;
  } else {
    answer += `Case ${index + 1}: Triple pangram!!!\n`;
  }
});

console.log(answer);