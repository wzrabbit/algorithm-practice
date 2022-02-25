let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
input.shift();
input = [...input[0].split(' ')].map(Number);

input.sort((a, b) => a - b);
let tempSum = 0;
let sum = 0;

for (let i = 0; i < input.length; i++) {
  sum += tempSum + input[i];
  tempSum += input[i];
}

console.log(sum);