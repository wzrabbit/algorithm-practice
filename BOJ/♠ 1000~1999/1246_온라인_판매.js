let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [egg, people] = input[0].split(' ').map(Number);
input.shift();
input = input.map(Number);
input.sort((a, b) => b - a);
let maxIncome = 0;
let maxEgg = 0;

for (let i = 1; i < input[0]; i++) {
  let income = getBuyAmount(i) * i;
  if (income > maxIncome) {
    maxIncome = income;
    maxEgg = i;
  }
}

console.log(maxEgg, maxIncome);

function getBuyAmount(price) {
  let amount = 0;
  for (let i = 0; i < input.length; i++) {
    if (input[i] >= price) amount++;
  }
  return Math.min(egg, amount);
}