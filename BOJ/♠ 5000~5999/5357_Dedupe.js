const [, ...input] = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
let printer = '';

input.forEach((testcase) => {
  printer += testcase.replace(/(.)\1+/g, (matched) => matched[0]) + '\n';
});

console.log(printer);