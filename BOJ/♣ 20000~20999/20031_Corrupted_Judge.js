let [NP, ...penalties] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const [_, P] = NP.split(' ').map(Number);
penalties = penalties.map(Number);

let currentCount = 0;
let previousPenalty = 0.5;
let isAllZero = true;
const answers = [];

penalties.reverse().forEach((penalty) => {
  if (penalty !== 0) {
    isAllZero = false;
  }

  if (penalty > previousPenalty) {
    currentCount += 1;
  }

  answers.push(currentCount);
  previousPenalty = penalty;
});

if (currentCount === P || isAllZero) {
  console.log(answers.reverse().join('\n'));
} else {
  console.log('ambiguous');
}
