const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const lengths = input.map((line) => line.length);
const maxLength = Math.max(...lengths);

let penaltyScore = 0;

for (let i = 0; i < lengths.length - 1; i++) {
  penaltyScore += (maxLength - lengths[i]) ** 2;
};

console.log(penaltyScore);
