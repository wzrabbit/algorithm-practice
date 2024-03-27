const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map(BigInt);

const N = input[0];
const keys = input.slice(1);

const isValidKey = (key) => {
  for (let i = 2n; i <= 1000000n; i++) {
    if (key % i === 0n) {
      return false;
    }
  }

  return true;
};

let output = '';

keys.forEach((key) => {
  output += `${isValidKey(key) ? 'YES' : 'NO'}\n`;
});

console.log(output);
