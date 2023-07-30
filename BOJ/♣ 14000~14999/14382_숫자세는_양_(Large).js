const getSleepNumber = startNumber => {
  if (startNumber === 0) {
    return 'INSOMNIA';
  }

  const digits = new Set();
  let currentNumber = 0;

  while (digits.size < 10) {
    currentNumber += startNumber;
    const currentDigits = currentNumber.toString().split("");

    currentDigits.forEach(digit => {
      digits.add(digit);
    });
  }

  return currentNumber;
};

const [N, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map(Number);

let printer = '';

input.forEach((testcase, index) => {
  printer += `Case #${index + 1}: ${getSleepNumber(testcase)}\n`;
});

console.log(printer);