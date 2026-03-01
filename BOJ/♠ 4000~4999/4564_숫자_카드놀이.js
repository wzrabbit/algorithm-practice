const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n').slice(0, -1).map(Number);

input.forEach((number) => {
  const result = [number];

  while (number >= 10) {
    number = String(number).split('').map(Number).reduce((acc, cur) => acc * cur, 1);
    result.push(number);
  }

  console.log(result.join(' '));
});
