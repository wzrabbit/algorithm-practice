const isArrayEqual = (arrayA, arrayB) => {
  return arrayA.every((value, index) => value === arrayB[index]);
}

const [, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const increasingArray = [...input].sort();
const decreasingArray = [...increasingArray].reverse();

if (isArrayEqual(input, increasingArray)) {
  console.log('INCREASING');
} else if (isArrayEqual(input, decreasingArray)) {
  console.log('DECREASING');
} else {
  console.log('NEITHER');
}