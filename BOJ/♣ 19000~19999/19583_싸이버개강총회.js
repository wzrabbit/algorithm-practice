const convertTimeToValue = (time) => {
  const [hour, minute] = time.split(':').map(Number);

  return hour * 60 + minute;
};

const [times, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const timeValues = times.split(' ').map((time) => convertTimeToValue(time));
const scores = {};

input.forEach((testcase) => {
  const [time, username] = testcase.split(' ');
  const userTimeValue = convertTimeToValue(time);

  if (!(username in scores)) {
    scores[username] = 0;
  }

  if (userTimeValue <= timeValues[0]) {
    scores[username] |= 1;
  }

  if (userTimeValue >= timeValues[1] && userTimeValue <= timeValues[2]) {
    scores[username] |= 2;
  }
});

const successCount = Object.values(scores)
  .reduce((acc, cur) => acc + ((cur === 3) ? 1 : 0), 0);

console.log(successCount);
