const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split("\n");

const [N, K] = input[0].split(" ").map(Number);
const arr = input[1].split(" ").map(Number);
const numbers = {};
let currentSum = 0;

for (let i = 0; i < N; i++) {
  currentSum = (currentSum + arr[i]) % K;

  if (currentSum in numbers) {
    numbers[currentSum] += 1;
  } else {
    numbers[currentSum] = 1;
  }
}

const answer = [...Object.values(numbers)].sort((a, b) => b - a)[0];
console.log(answer);
