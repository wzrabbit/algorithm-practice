const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

let printer = '';

for (let i = 0; i < input.length - 1; i++) {
  const [calorie, fat, carbo, protein] = input[i]
    .split(' ')
    .map(x => parseInt(x) * 10);

  const minSumCalorie = Math.max(fat - 5, 0) * 9 + Math.max(carbo - 5, 0) * 4 + Math.max(protein - 5, 0) * 4;
  const maxSumCalorie = (fat + 5) * 9 + (carbo + 5) * 4 + (protein + 5) * 4;

  if (
    calorie >= Math.round(minSumCalorie / 10) * 10 &&
    calorie < Math.round(maxSumCalorie / 10) * 10
  ) {
    printer += 'yes\n';
  } else {
    printer += 'no\n';
  }
}

console.log(printer);