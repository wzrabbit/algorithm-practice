const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0]);
const top = input[1].split(' ').map(Number);
const bottom = input[2].split(' ').map(Number);
const heights = new Array(N);
const Q = Number(input[3]);
const birdSizes = input[4].split(' ').map(Number);
const answer = new Array(Q);

heights[0] = top[0] - bottom[0];

for (let i = 1; i < N; i += 1) {
  heights[i] = Math.min(heights[i - 1], top[i] - bottom[i]);
}

birdSizes.forEach((birdSize, index) => {
  let start = 0;
  let end = N - 1;
  
  while (start <= end) {
    const mid = Math.floor((start + end) / 2);

    if (birdSize > heights[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }

    answer[index] = end + 1;
  }
});

console.log(answer.join('\n'));
