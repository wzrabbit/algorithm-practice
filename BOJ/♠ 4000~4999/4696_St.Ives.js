const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n').map((num) => parseFloat(num));
let printer = '';
input.pop();

input.forEach((testcase) => {
  const calc = (1 + testcase + testcase ** 2 + testcase ** 3 + testcase ** 4).toFixed(2);
  printer += calc + '\n';
});

console.log(printer);