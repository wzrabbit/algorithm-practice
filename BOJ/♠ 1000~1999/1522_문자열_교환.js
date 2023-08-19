const S = require('fs')
  .readFileSync(0, 'utf-8')
  .toString()
  .trim()
  .repeat(2);

const bCount = (S.match(/b/) || []).length;

let maxBCount = 0;
let curBCount = 0;

for (let i = 0; i < bCount; i++) {
  if (S[i] === 'b') {
    curBCount += 1;
  }
}

maxBCount = curBCount;

for (let i = bCount; i < S.length; i++) {
  if (S[i] === 'b') {
    curBCount += 1;
  }

  if (S[i - bCount] === 'b') {
    curBCount -= 1;
  }

  maxBCount = Math.max(maxBCount, curBCount);
}

console.log(bCount - maxBCount);
