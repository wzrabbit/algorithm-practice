const [N, M] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map(Number);

const isAnswer = (number) => {
  if (/[23457]/.test(number)) {
    return false;
  }

  const rotatedNumber = number
    .replaceAll('6', 'X')
    .replaceAll('9', '6')
    .replaceAll('X', '9')
    .split('')
    .reverse()
    .join('');

  return Number(rotatedNumber) === Number(number);
};

let answerCount = 0;

for (let i = N; i <= M; i++) {
  if (isAnswer(String(i))) {
    answerCount += 1;
  }
}

console.log(answerCount);
