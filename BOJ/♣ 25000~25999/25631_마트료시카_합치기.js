let [, dolls] = require('fs')
  .readFileSync(0, 'utf-8')
  .split('\n');

dolls = dolls.split(' ').map(Number);
const dollCounts = {};

dolls.forEach((doll) => {
  if (dollCounts.hasOwnProperty(doll)) {
    dollCounts[doll] += 1;
  } else {
    dollCounts[doll] = 1;
  }
});

const maxDollCount = Math.max(...Object.values(dollCounts));
console.log(maxDollCount);