const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim();

const alphabetCounts = new Array(26).fill(0);

for (let i = 0; i < input.length; i++) {
  const charCode = input.charCodeAt(i) - 65;
  alphabetCounts[charCode] += 1;
}

const isPossible = alphabetCounts.filter(count => count % 2 === 1).length <= 1;

if (isPossible) {
  let leftString = '';
  let midString = '';

  for (let i = 0; i < 26; i++) {
    const currentLetter = String.fromCharCode(65 + i);

    leftString += currentLetter.repeat(Math.floor(alphabetCounts[i] / 2));
    midString += currentLetter.repeat(alphabetCounts[i] % 2);
  }

  const rightString = leftString
    .split('')
    .reverse()
    .join('');

  console.log(`${leftString}${midString}${rightString}`);
} else {
  console.log("I'm Sorry Hansoo");
}