const [, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .toString()
  .trim()
  .split('\n');

const dayCounts = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
let printer = '';

input.forEach((testcase) => {
  const isUsed = testcase.split(' ').map(Number);
  let answer = 0;

  for (let m = 1; m <= 12; m++) {
    for (let d = 1; d <= dayCounts[m]; d++) {
      const includedNumbers = (m.toString() + d.toString())
        .split('')
        .map(Number);

      const isValid = includedNumbers.every((number) => !isUsed[number]);

      if (isValid) {
        answer += 1;
      }
    }
  }

  printer += `${answer}\n`;
});

console.log(printer);