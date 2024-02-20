const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map(BigInt);

input.pop();

let output = '';

input.forEach((number) => {
  const bit = (number - 1n).toString(2);
  const selectedNumbers = [];
  let currentNumber = 1n;

  for (let i = bit.length - 1; i >= 0; i--) {
    if (bit[i] === '1') {
      selectedNumbers.push(currentNumber);
    }

    currentNumber *= 3n;
  }

  output += `{ ${selectedNumbers.join(', ')}${number === 1n ? '' : ' '}}\n`;
});

console.log(output);
