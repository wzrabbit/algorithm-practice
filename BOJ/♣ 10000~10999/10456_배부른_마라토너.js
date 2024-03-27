const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0]);
const participants = input.slice(1, N + 1);
const finishers = input.slice(N + 1);
const finishCounts = {};

finishers.forEach((finisher) => {
  if (!finishCounts[finisher]) {
    finishCounts[finisher] = 1;
  } else {
    finishCounts[finisher] += 1;
  }
})

let answer = '';

participants.forEach((participant) => {
  if (finishCounts[participant]) {
    finishCounts[participant] -= 1;
  } else {
    answer = participant;
  }
});

console.log(answer);
