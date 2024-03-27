const generateNumbersByDigitCount = (digitCount) => {
  for (let i = 0; i < K ** digitCount; i++) {
    let curNumber = i;
    let result = '';

    for (let j = 0; j < digitCount; j++) {
      result += elements[curNumber % K];
      curNumber = Math.floor(curNumber / K);
    }

    candidates.push(Number(result));
  }
};

const generateNumbers = () => {
  for (let i = 1; i <= 8; i++) {
    generateNumbersByDigitCount(i);
  }
};

const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const [N, K] = input[0].split(' ').map(Number);
const elements = input[1].split(' ');
const candidates = [];
let maxNumber = 0;

generateNumbers();

for (let i = 0; i < candidates.length; i++) {
  if (candidates[i] <= N && candidates[i] > maxNumber) {
    maxNumber = candidates[i];
  }
}

console.log(candidates.length);
console.log(maxNumber);
