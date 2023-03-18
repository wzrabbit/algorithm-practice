const [N, word]: [number, string] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const matchedNumbers: string[] = word.match(/\d+/g) || [];

console.log(
  matchedNumbers.length === 0
    ? 'N/A'
    : matchedNumbers
        .map((currentNumber: string) => Number(currentNumber) * N)
        .join('\n')
);
