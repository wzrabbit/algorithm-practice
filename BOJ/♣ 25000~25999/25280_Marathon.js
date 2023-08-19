const isPossible = (finishTime) => {
  let probability = 1;

  ranges.forEach((range) => {
    const [start, end] = range;
    let totalArea = end - start;
    let winningArea = Math.min(totalArea, Math.max(0, end - finishTime));

    probability *= winningArea / totalArea;
  });

  return probability >= 0.5;
};

const [_, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const ranges = input.map((line) => line.split(' ').map(Number));

let start = 0;
let end = 100000;
let mid;

for (let i = 0; i < 40; i++) {
  mid = (start + end) / 2;

  if (isPossible(mid)) {
    start = mid;
  } else {
    end = mid;
  }
}

console.log(end);
