const [NMK, ...arr] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const [N, M] = NMK.split(' ').map(Number);
const oldLimits = arr.slice(0, N).map(Number);
const newLimits = arr.slice(N, N + M).map(Number);
const oldSum = oldLimits.reduce((acc, cur) => acc + cur);
const newSum = newLimits.reduce((acc, cur) => acc + cur);
const possibleMoveAmount = Math.min(oldSum, newSum);
let oldIndex = 0;
let newIndex = 0;
let cost = 0;

while (true) {
  while (oldLimits[oldIndex] === 0) {
    oldIndex += 1;
  }

  while (newLimits[newIndex] === 0) {
    newIndex += 1;
  }

  if (oldIndex >= N || newIndex >= M) {
    break;
  }

  const matches = Math.min(oldLimits[oldIndex], newLimits[newIndex]);

  cost += (oldIndex + newIndex + 2) * matches;
  oldLimits[oldIndex] -= matches;
  newLimits[newIndex] -= matches;
}

console.log(possibleMoveAmount, cost);
