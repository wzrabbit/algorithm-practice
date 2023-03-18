const [, ...input]: [never, ...string[]] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

let printer: string = '';

input.forEach((testcase, index) => {
  if (index % 2 === 1) {
    const numbers = testcase.split(/[=+]/).map(Number);

    if (isNaN(numbers[0]))
      printer += `${numbers[2] - numbers[1]} + ${numbers[1]} = ${numbers[2]}\n`;
    if (isNaN(numbers[1]))
      printer += `${numbers[0]} + ${numbers[2] - numbers[0]} = ${numbers[2]}\n`;
    if (isNaN(numbers[2]))
      printer += `${numbers[0]} + ${numbers[1]} = ${numbers[0] + numbers[1]}\n`;
  }
});

console.log(printer);
