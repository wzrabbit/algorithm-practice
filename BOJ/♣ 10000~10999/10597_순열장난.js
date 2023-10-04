let input = require('fs').readFileSync(0, 'utf-8').trim();
const S = input.length;
const N = Math.min(S, 9) + Math.max((S - 9) / 2, 0);

const backtrack = (index, number) => {
  if (killSwitch) {
    return;
  }

  isUsed[number] = true;
  numbers.push(number);

  if (index === S) {
    console.log(numbers.join(' '));
    killSwitch = true;

    return;
  }

  const shortNumber = Number(input[index]);
  const longNumber = Number(input[index] + input[index + 1]);

  if (shortNumber !== 0 && !isUsed[shortNumber]) {
    backtrack(index + 1, shortNumber);
  }

  if (longNumber >= 10 && longNumber <= N && !isUsed[longNumber]) {
    backtrack(index + 2, longNumber);
  }

  isUsed[number] = false;
  numbers.pop();
}


if (N === 1) {
  console.log(1);
  return;
}

const isUsed = new Array(N + 1).fill(0);
const numbers = [];
const twoDigitNumber = Number(input[0] + input[1]);
let killSwitch = false;

backtrack(1, Number(input[0]));

if (input[0] !== '0' && Number(input[0] + input[1]) <= N) {
  backtrack(2, twoDigitNumber);
}
