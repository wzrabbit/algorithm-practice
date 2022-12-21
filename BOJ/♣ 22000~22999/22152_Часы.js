const [, ...input] = require("fs")
  .readFileSync(0, "utf-8")
  .toString()
  .trim()
  .split("\n")
  .map((x) => x.split(" ").map(Number));

let printer = "";
const INVISIBLE = -1;

let isHiddenTime;

const fillHiddenTime = (hiddenArea) => {
  isHiddenTime = new Array(60).fill(true);

  if (hiddenArea.start <= hiddenArea.end) {
    for (let i = hiddenArea.start; i <= hiddenArea.end; i += 1) {
      isHiddenTime[i] = false;
    }
    return;
  }

  for (let i = hiddenArea.start; i <= 59; i += 1) {
    isHiddenTime[i] = false;
  }

  for (let i = 0; i <= hiddenArea.end; i += 1) {
    isHiddenTime[i] = false;
  }
};

const isPossibleTime = (hour, minute, hourHand, minuteHand) => {
  if (hourHand === INVISIBLE) {
    if (!isHiddenTime[hour]) {
      return false;
    }
  } else {
    if (hourHand !== hour) {
      return false;
    }
  }

  if (minuteHand === INVISIBLE) {
    if (!isHiddenTime[minute]) {
      return false;
    }
  } else {
    if (minuteHand !== minute) {
      return false;
    }
  }

  return true;
};

const increaseTime = (hour, minute) => {
  minute = (minute + 1) % 60;
  if (minute % 12 === 0) hour += 1;
  return { hour, minute };
};

for (const testCase of input) {
  const hiddenArea = { start: testCase[0], end: testCase[1] };
  const [hourHand, minuteHand] = [testCase[2], testCase[3]];
  let [hour, minute] = [0, 0];
  let possibleCount = 0;

  fillHiddenTime(hiddenArea);

  while (hour < 60) {
    if (isPossibleTime(hour, minute, hourHand, minuteHand)) possibleCount += 1;
    ({ hour, minute } = increaseTime(hour, minute));
  }

  printer += `${possibleCount}\n`;
}

console.log(printer);
