const simulate = (number) => {
  let currentNumber = number;
  const digitSet = new Set(String(currentNumber));

  output += `N=${currentNumber}:\n`;

  if (String(currentNumber).length !== 4 || digitSet.size === 1) {
    output += `No!!\n`;
    return;
  }

  let repeatCount = 0;

  while (currentNumber !== 0 && currentNumber !== 6174) {
    const bigNumber = Number(String(currentNumber).split('').sort().reverse().join(''));
    const smallNumber = Number(String(currentNumber).split('').sort().join(''));
    const resultNumber = bigNumber - smallNumber;

    output += `${bigNumber}-${smallNumber}=${resultNumber}\n`;
    currentNumber = resultNumber;
    repeatCount += 1;
  }

  output += `Ok!! ${repeatCount} times\n`
};

const queries = require('fs').readFileSync(0, 'utf-8').trim().split('\n').slice(0, -1).map(Number);
let output = '';

queries.forEach((query) => {
  simulate(query);
});

console.log(output);
