const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0]);
const testcases = input.slice(1);
let output = '';

testcases.forEach((testcase) => {
  const [A, B] = testcase.split(' ').map(Number);
  output += `${Math.abs(A - B).toFixed(1)}\n`;
});

console.log(output);
