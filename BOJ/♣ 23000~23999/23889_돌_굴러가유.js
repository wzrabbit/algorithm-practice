const [NMK, castles, stones] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map((line) => line.split(' ').map(Number));

const [N, M, K] = NMK;
const advantages = [];
let sum = 0;
let stoneNo = -1;
let stoneIndex = 0;
stones.push(N + 1);

for (let i = stones[0] - 1; i < N; i++) {
  if (i === stones[stoneIndex] - 1) {
    advantages.push([stoneNo, sum]);
    sum = 0;
    stoneNo = i + 1;
    stoneIndex += 1;
  }

  sum += castles[i];
}

advantages.push([stoneNo, sum]);

advantages.sort((a, b) => {
  if (a[1] !== b[1]) {
    return b[1] - a[1];
  }

  return a[0] - b[0];
});

const answers = advantages.slice(0, M).map((advantage) => advantage[0]);
answers.sort((a, b) => a - b);

console.log(answers.join('\n'));