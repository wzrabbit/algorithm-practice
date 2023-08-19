const isPossible = (sliceSize) => {
  let lineCount = 0;

  input.forEach((line) => {
    lineCount += Math.floor(line / sliceSize);
  });

  return lineCount >= M;
}

const [NM, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const M = NM.split(' ')[1];

let start = 1;
let end = 2 ** 31 - 1;
let mid;

while (start <= end) {
  mid = Math.floor((start + end) / 2);

  if (isPossible(mid)) {
    start = mid + 1;
  } else {
    end = mid - 1;
  }
}

console.log(end);
